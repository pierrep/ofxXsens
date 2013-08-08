#pragma once

#include <list>

//--------------------------------------------------------------------------------
// CallbackHandler is an object derived from XsCallback that can be attached to
// an XsDevice using the XsDevice::setCallbackHandler method.
// Various virtual methods which are automatically called by the XsDevice can be
// overridden (See XsCallback)
// Only the onPostProcess(...) method is overridden here. This method is called
// when a new data packet is available.
// Note that this method will be called from within the thread of the XsDevice so
// proper synchronisation is required.
// It is recommended to keep the implementation of these methods fast; therefore
// the only action here is to copy the packet to a queue where it can be
// retrieved later by the main thread to be displayed. All access to the queue is
// protected by a critical section because multiple threads are accessing it.
//--------------------------------------------------------------------------------
class CallbackHandler : public XsCallback
{
public:
	CallbackHandler(size_t maxBufferSize = 5) : m_maxNumberOfPacketsInBuffer(maxBufferSize), m_numberOfPacketsInBuffer(0)
#ifdef _MSC_VER
	{InitializeCriticalSection(&m_CriticalSection);}
	virtual ~CallbackHandler() throw() {DeleteCriticalSection(&m_CriticalSection);}
#else
	{
	  //create mutex attribute variable
	  pthread_mutexattr_t mAttr;

	  // setup recursive mutex for mutex attribute
	  pthread_mutexattr_settype(&mAttr, PTHREAD_MUTEX_RECURSIVE_NP);

	  // Use the mutex attribute to create the mutex
	  pthread_mutex_init(&m_CriticalSection, &mAttr);

	  // Mutex attribute can be destroy after initializing the mutex variable
	  pthread_mutexattr_destroy(&mAttr);

	}
	virtual ~CallbackHandler() throw() {pthread_mutex_destroy(&m_CriticalSection);}
#endif

	bool packetAvailable() const {Locker lock(*this); return m_numberOfPacketsInBuffer > 0;}
	XsDataPacket getNextPacket()
	{
		assert(packetAvailable());
		Locker lock(*this);
		XsDataPacket oldestPacket(m_packetBuffer.front());
		m_packetBuffer.pop_front();
		--m_numberOfPacketsInBuffer;
		return oldestPacket;
	}

protected:
	virtual void onDataAvailable(XsDevice*, const XsDataPacket* packet)
	{
		Locker lock(*this);
		assert(packet != 0);
		while (m_numberOfPacketsInBuffer >= m_maxNumberOfPacketsInBuffer)
		{
			(void)getNextPacket();
		}
		m_packetBuffer.push_back(*packet);
		++m_numberOfPacketsInBuffer;
		assert(m_numberOfPacketsInBuffer <= m_maxNumberOfPacketsInBuffer);
	}
private:
#ifdef _MSC_VER
	mutable CRITICAL_SECTION m_CriticalSection;
#else
	mutable pthread_mutex_t m_CriticalSection;
#endif
	struct Locker
	{
#ifdef _MSC_VER
		Locker(CallbackHandler const & self) : m_self(self) {EnterCriticalSection(&m_self.m_CriticalSection);}
		~Locker() throw() {LeaveCriticalSection(&m_self.m_CriticalSection);}
#else
		Locker(CallbackHandler const & self) : m_self(self) {pthread_mutex_lock(&m_self.m_CriticalSection);}
		~Locker() throw() {pthread_mutex_unlock(&m_self.m_CriticalSection);}
#endif
		CallbackHandler const & m_self;
	};
	size_t m_maxNumberOfPacketsInBuffer;
	size_t m_numberOfPacketsInBuffer;
	std::list<XsDataPacket> m_packetBuffer;
};
