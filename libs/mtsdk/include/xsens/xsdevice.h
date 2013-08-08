#ifndef GUARD_XSDEVICE_H
#define GUARD_XSDEVICE_H
#include <xsens/pstdint.h>
#include <xsens/xstypedefs.h>
#include "xsstring.h"
#include "xsdeviceid.h"
#include "xssyncsetting.h"
#include "xsversion.h"
#include "xsscrdata.h"
#include "xscalibrateddata.h"
#include "xsfilterprofile.h"
#include "xscallbackplainc.h"
#include "xsselftestresult.h"
#include "xsutctime.h"
#include "xsdevicemode.h"
#include "xsoutputconfigurationarray.h"
#include "xsdatapacket.h"
#include "xsmessage.h"
#include "xsbaud.h"
#include "xsresultvalue.h"
#include "xsdevicestate.h"
#include "xssyncrole.h"
#include "xsresetmethod.h"
#include "xserrormode.h"
#include "xsoutputmode.h"
#include "xsoutputsettings.h"
#include "xsdeviceptrarray.h"
#include "xsintlist.h"
#include "xsoutputconfigurationarray.h"
#include "xssyncsettingarray.h"
#include "xsfilterprofilearray.h"
#include "xsdeviceconfiguration.h"
#include "xsxbusmessageid.h"
#include "xsfilepos.h"
#include "xsprotocoltype.h"
#include "xsoption.h"
#include "xsqueuemode.h"
#include "xsrejectreason.h"
#ifdef __cplusplus
extern "C" {
#endif
/*! \addtogroup cinterface C Interface
	@{ */
struct XsDevice;
typedef struct XsDevice XsDevice;
XDA_DLL_API XsDevice* XsDevice_master(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::master() const 
XDA_DLL_API XsDevicePtrArray* XsDevice_children(const struct XsDevice* thisPtr, XsDevicePtrArray* returnValue);//!< \copydoc XsDevice::children() const 
XDA_DLL_API XsDevice* XsDevice_findDevice(const struct XsDevice* thisPtr, XsDeviceId deviceid);//!< \copydoc XsDevice::findDevice(XsDeviceId) const 
XDA_DLL_API int XsDevice_busId(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::busId() const 
XDA_DLL_API XsDeviceId* XsDevice_deviceId(const struct XsDevice* thisPtr, XsDeviceId* returnValue);//!< \copydoc XsDevice::deviceId() const 
XDA_DLL_API XsVersion* XsDevice_firmwareVersion(const struct XsDevice* thisPtr, XsVersion* returnValue);//!< \copydoc XsDevice::firmwareVersion() const 
XDA_DLL_API int XsDevice_isMasterDevice(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isMasterDevice() const 
XDA_DLL_API int XsDevice_isInitialized(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isInitialized() const 
XDA_DLL_API const XsDevice* XsDevice_deviceAtBusId(const struct XsDevice* thisPtr, int busid);//!< \copydoc XsDevice::deviceAtBusId(int) const 
XDA_DLL_API XsDevice* XsDevice_deviceAtBusId_1(struct XsDevice* thisPtr, int busid);//!< \copydoc XsDevice::deviceAtBusId(int) 
XDA_DLL_API void XsDevice_setGotoConfigOnClose(struct XsDevice* thisPtr, int gotoConfigOnClose);//!< \copydoc XsDevice::setGotoConfigOnClose(bool) 
XDA_DLL_API XsResultValue XsDevice_createLogFile(struct XsDevice* thisPtr, const XsString* filename);//!< \copydoc XsDevice::createLogFile(const XsString&) 
XDA_DLL_API int XsDevice_closeLogFile(struct XsDevice* thisPtr);//!< \copydoc XsDevice::closeLogFile() 
XDA_DLL_API int XsDevice_isMeasuring(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isMeasuring() const 
XDA_DLL_API int XsDevice_isRecording(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isRecording() const 
XDA_DLL_API int XsDevice_isReadingFromFile(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isReadingFromFile() const 
XDA_DLL_API void XsDevice_restartFilter(struct XsDevice* thisPtr);//!< \copydoc XsDevice::restartFilter() 
XDA_DLL_API int XsDevice_queueLength(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::queueLength() const 
XDA_DLL_API XsDeviceState XsDevice_deviceState(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::deviceState() const 
XDA_DLL_API XsDataPacket* XsDevice_nextAvailableDataPacket(struct XsDevice* thisPtr, XsDataPacket* returnValue);//!< \copydoc XsDevice::nextAvailableDataPacket() 
XDA_DLL_API XsDataPacket* XsDevice_dataPacketByIndex(struct XsDevice* thisPtr, XsDataPacket* returnValue, uint32_t index);//!< \copydoc XsDevice::dataPacketByIndex(uint32_t) 
XDA_DLL_API XsDataPacket* XsDevice_dataPacketById(struct XsDevice* thisPtr, XsDataPacket* returnValue, uint64_t packetId);//!< \copydoc XsDevice::dataPacketById(uint64_t) 
XDA_DLL_API void XsDevice_clearCallbackHandlers(struct XsDevice* thisPtr, int chain);//!< \copydoc XsDevice::clearCallbackHandlers(bool) 
XDA_DLL_API void XsDevice_addCallbackHandler(struct XsDevice* thisPtr, XsCallbackPlainC* cb, int chain);//!< \copydoc XsDevice::addCallbackHandler(XsCallbackPlainC*,bool) 
XDA_DLL_API void XsDevice_removeCallbackHandler(struct XsDevice* thisPtr, XsCallbackPlainC* cb, int chain);//!< \copydoc XsDevice::removeCallbackHandler(XsCallbackPlainC*,bool) 
XDA_DLL_API XsDeviceConfiguration* XsDevice_deviceConfiguration(const struct XsDevice* thisPtr, XsDeviceConfiguration* returnValue);//!< \copydoc XsDevice::deviceConfiguration() const 
XDA_DLL_API void XsDevice_clear(struct XsDevice* thisPtr);//!< \copydoc XsDevice::clear() 
XDA_DLL_API int XsDevice_batteryLevel(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::batteryLevel() const 
XDA_DLL_API int XsDevice_updateRateForDataIdentifier(const struct XsDevice* thisPtr, XsDataIdentifier dataType);//!< \copydoc XsDevice::updateRateForDataIdentifier(XsDataIdentifier) const 
XDA_DLL_API int XsDevice_updateRateForProcessedDataIdentifier(const struct XsDevice* thisPtr, XsDataIdentifier dataType);//!< \copydoc XsDevice::updateRateForProcessedDataIdentifier(XsDataIdentifier) const 
XDA_DLL_API XsIntArray* XsDevice_supportedUpdateRates(const struct XsDevice* thisPtr, XsIntArray* returnValue, XsDataIdentifier dataType);//!< \copydoc XsDevice::supportedUpdateRates(XsDataIdentifier) const 
XDA_DLL_API int XsDevice_maximumUpdateRate(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::maximumUpdateRate() const 
XDA_DLL_API int XsDevice_hasDataEnabled(const struct XsDevice* thisPtr, XsDataIdentifier dataType);//!< \copydoc XsDevice::hasDataEnabled(XsDataIdentifier) const 
XDA_DLL_API int XsDevice_hasProcessedDataEnabled(const struct XsDevice* thisPtr, XsDataIdentifier dataType);//!< \copydoc XsDevice::hasProcessedDataEnabled(XsDataIdentifier) const 
XDA_DLL_API XsString* XsDevice_productCode(const struct XsDevice* thisPtr, XsString* returnValue);//!< \copydoc XsDevice::productCode() const 
XDA_DLL_API XsString* XsDevice_portName(const struct XsDevice* thisPtr, XsString* returnValue);//!< \copydoc XsDevice::portName() const 
XDA_DLL_API XsBaudRate* XsDevice_baudRate(const struct XsDevice* thisPtr, XsBaudRate* returnValue);//!< \copydoc XsDevice::baudRate() const 
XDA_DLL_API XsBaudRate* XsDevice_serialBaudRate(const struct XsDevice* thisPtr, XsBaudRate* returnValue);//!< \copydoc XsDevice::serialBaudRate() const 
XDA_DLL_API XsVersion* XsDevice_hardwareVersion(const struct XsDevice* thisPtr, XsVersion* returnValue);//!< \copydoc XsDevice::hardwareVersion() const 
XDA_DLL_API int XsDevice_startRecording(struct XsDevice* thisPtr);//!< \copydoc XsDevice::startRecording() 
XDA_DLL_API int XsDevice_stopRecording(struct XsDevice* thisPtr);//!< \copydoc XsDevice::stopRecording() 
XDA_DLL_API int XsDevice_setOptionEnabled(struct XsDevice* thisPtr, XsOption option, int enabled);//!< \copydoc XsDevice::setOptionEnabled(XsOption,bool) 
XDA_DLL_API int XsDevice_isOptionEnabled(const struct XsDevice* thisPtr, XsOption option);//!< \copydoc XsDevice::isOptionEnabled(XsOption) const 
XDA_DLL_API int XsDevice_initializeFilter(struct XsDevice* thisPtr);//!< \copydoc XsDevice::initializeFilter() 
XDA_DLL_API int XsDevice_sendCustomMessage(struct XsDevice* thisPtr, const XsMessage* messageSend, int waitForResult, XsMessage* messageReceive, int timeout);//!< \copydoc XsDevice::sendCustomMessage(const XsMessage&,bool,XsMessage&,int) 
XDA_DLL_API int XsDevice_sendRawMessage(struct XsDevice* thisPtr, const XsMessage* message);//!< \copydoc XsDevice::sendRawMessage(const XsMessage&) 
XDA_DLL_API int XsDevice_setSerialBaudRate(struct XsDevice* thisPtr, XsBaudRate baudrate);//!< \copydoc XsDevice::setSerialBaudRate(XsBaudRate) 
XDA_DLL_API int XsDevice_isMotionTracker(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isMotionTracker() const 
XDA_DLL_API XsOutputMode XsDevice_outputMode(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::outputMode() const 
XDA_DLL_API int XsDevice_setOutputMode(struct XsDevice* thisPtr, XsOutputMode mode);//!< \copydoc XsDevice::setOutputMode(XsOutputMode) 
XDA_DLL_API XsOutputSettings XsDevice_outputSettings(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::outputSettings() const 
XDA_DLL_API int XsDevice_setOutputSettings(struct XsDevice* thisPtr, XsOutputSettings outputsettings);//!< \copydoc XsDevice::setOutputSettings(XsOutputSettings) 
XDA_DLL_API int XsDevice_updateRate(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::updateRate() const 
XDA_DLL_API int XsDevice_setUpdateRate(struct XsDevice* thisPtr, int rate);//!< \copydoc XsDevice::setUpdateRate(int) 
XDA_DLL_API XsOutputConfigurationArray* XsDevice_outputConfiguration(const struct XsDevice* thisPtr, XsOutputConfigurationArray* returnValue);//!< \copydoc XsDevice::outputConfiguration() const 
XDA_DLL_API XsOutputConfigurationArray* XsDevice_processedOutputConfiguration(const struct XsDevice* thisPtr, XsOutputConfigurationArray* returnValue);//!< \copydoc XsDevice::processedOutputConfiguration() const 
XDA_DLL_API int XsDevice_setOutputConfiguration(struct XsDevice* thisPtr, XsOutputConfigurationArray* config);//!< \copydoc XsDevice::setOutputConfiguration(XsOutputConfigurationArray&) 
XDA_DLL_API int XsDevice_isInLegacyMode(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isInLegacyMode() const 
XDA_DLL_API uint16_t XsDevice_samplePeriod(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::samplePeriod() const 
XDA_DLL_API int XsDevice_setSamplePeriod(struct XsDevice* thisPtr, uint16_t period);//!< \copydoc XsDevice::setSamplePeriod(uint16_t) 
XDA_DLL_API uint16_t XsDevice_outputSkipFactor(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::outputSkipFactor() const 
XDA_DLL_API int XsDevice_setOutputSkipFactor(struct XsDevice* thisPtr, uint16_t skipFactor);//!< \copydoc XsDevice::setOutputSkipFactor(uint16_t) 
XDA_DLL_API XsDeviceMode* XsDevice_deviceMode(const struct XsDevice* thisPtr, XsDeviceMode* returnValue);//!< \copydoc XsDevice::deviceMode() const 
XDA_DLL_API int XsDevice_setDeviceMode(struct XsDevice* thisPtr, const XsDeviceMode* mode);//!< \copydoc XsDevice::setDeviceMode(const XsDeviceMode&) 
XDA_DLL_API int XsDevice_dataLength(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::dataLength() const 
XDA_DLL_API void XsDevice_clearCache(struct XsDevice* thisPtr);//!< \copydoc XsDevice::clearCache() 
XDA_DLL_API XsSyncSettingArray* XsDevice_syncSettings(const struct XsDevice* thisPtr, XsSyncSettingArray* returnValue);//!< \copydoc XsDevice::syncSettings() const 
XDA_DLL_API int XsDevice_setSyncSettings(struct XsDevice* thisPtr, const XsSyncSettingArray* settingList);//!< \copydoc XsDevice::setSyncSettings(const XsSyncSettingArray&) 
XDA_DLL_API int XsDevice_isSyncMaster(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isSyncMaster() const 
XDA_DLL_API int XsDevice_isSyncSlave(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isSyncSlave() const 
XDA_DLL_API XsSyncSettingArray* XsDevice_supportedSyncSettings(const struct XsDevice* thisPtr, XsSyncSettingArray* returnValue);//!< \copydoc XsDevice::supportedSyncSettings() const 
XDA_DLL_API int XsDevice_gotoMeasurement(struct XsDevice* thisPtr);//!< \copydoc XsDevice::gotoMeasurement() 
XDA_DLL_API int XsDevice_gotoConfig(struct XsDevice* thisPtr);//!< \copydoc XsDevice::gotoConfig() 
XDA_DLL_API int XsDevice_restoreFactoryDefaults(struct XsDevice* thisPtr);//!< \copydoc XsDevice::restoreFactoryDefaults() 
XDA_DLL_API int XsDevice_reset(struct XsDevice* thisPtr);//!< \copydoc XsDevice::reset() 
XDA_DLL_API void XsDevice_writeDeviceSettingsToFile(struct XsDevice* thisPtr);//!< \copydoc XsDevice::writeDeviceSettingsToFile() 
XDA_DLL_API void XsDevice_flushInputBuffers(struct XsDevice* thisPtr, int complete);//!< \copydoc XsDevice::flushInputBuffers(bool) 
XDA_DLL_API XsSyncRole XsDevice_syncRole(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::syncRole() const 
XDA_DLL_API int XsDevice_loadLogFile(struct XsDevice* thisPtr);//!< \copydoc XsDevice::loadLogFile() 
XDA_DLL_API int XsDevice_abortLoadLogFile(struct XsDevice* thisPtr);//!< \copydoc XsDevice::abortLoadLogFile() 
XDA_DLL_API XsString* XsDevice_logFileName(const struct XsDevice* thisPtr, XsString* returnValue);//!< \copydoc XsDevice::logFileName() const 
XDA_DLL_API int XsDevice_droppedPacketCount(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::droppedPacketCount() const 
XDA_DLL_API int XsDevice_resetOrientation(struct XsDevice* thisPtr, XsResetMethod resetmethod);//!< \copydoc XsDevice::resetOrientation(XsResetMethod) 
XDA_DLL_API XsXbusMessageId XsDevice_peekMessageId(struct XsDevice* thisPtr);//!< \copydoc XsDevice::peekMessageId() 
XDA_DLL_API int XsDevice_resetLogFileReadPosition(struct XsDevice* thisPtr);//!< \copydoc XsDevice::resetLogFileReadPosition() 
XDA_DLL_API XsFilePos XsDevice_logFileSize(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::logFileSize() const 
XDA_DLL_API XsFilePos XsDevice_logFileReadPosition(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::logFileReadPosition() const 
XDA_DLL_API int XsDevice_updateCachedDeviceInformation(struct XsDevice* thisPtr);//!< \copydoc XsDevice::updateCachedDeviceInformation() 
XDA_DLL_API int XsDevice_resetDroppedPacketCount(struct XsDevice* thisPtr);//!< \copydoc XsDevice::resetDroppedPacketCount() 
XDA_DLL_API int XsDevice_setQueueMode(struct XsDevice* thisPtr, XsQueueMode mode);//!< \copydoc XsDevice::setQueueMode(XsQueueMode) 
XDA_DLL_API XsQueueMode XsDevice_queueMode(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::queueMode() const 
XDA_DLL_API XsConnectivityState* XsDevice_connectivityState(const struct XsDevice* thisPtr, XsConnectivityState* returnValue);//!< \copydoc XsDevice::connectivityState() const 
XDA_DLL_API int XsDevice_enableRadio(struct XsDevice* thisPtr, int channel);//!< \copydoc XsDevice::enableRadio(int) 
XDA_DLL_API int XsDevice_disableRadio(struct XsDevice* thisPtr);//!< \copydoc XsDevice::disableRadio() 
XDA_DLL_API int XsDevice_radioChannel(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::radioChannel() const 
XDA_DLL_API int XsDevice_isRadioEnabled(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isRadioEnabled() const 
XDA_DLL_API int XsDevice_makeOperational(struct XsDevice* thisPtr);//!< \copydoc XsDevice::makeOperational() 
XDA_DLL_API int XsDevice_isOperational(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isOperational() const 
XDA_DLL_API int XsDevice_abortFlushing(struct XsDevice* thisPtr);//!< \copydoc XsDevice::abortFlushing() 
XDA_DLL_API int XsDevice_setDeviceAccepted(struct XsDevice* thisPtr, const XsDeviceId* deviceId);//!< \copydoc XsDevice::setDeviceAccepted(const XsDeviceId&) 
XDA_DLL_API int XsDevice_setDeviceRejected(struct XsDevice* thisPtr, const XsDeviceId* deviceId);//!< \copydoc XsDevice::setDeviceRejected(const XsDeviceId&) 
XDA_DLL_API int XsDevice_acceptConnection(struct XsDevice* thisPtr);//!< \copydoc XsDevice::acceptConnection() 
XDA_DLL_API int XsDevice_rejectConnection(struct XsDevice* thisPtr);//!< \copydoc XsDevice::rejectConnection() 
XDA_DLL_API int XsDevice_wirelessPriority(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::wirelessPriority() const 
XDA_DLL_API int XsDevice_setWirelessPriority(struct XsDevice* thisPtr, int priority);//!< \copydoc XsDevice::setWirelessPriority(int) 
XDA_DLL_API XsRejectReason XsDevice_rejectReason(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::rejectReason() const 
XDA_DLL_API int XsDevice_requestBatteryLevel(struct XsDevice* thisPtr);//!< \copydoc XsDevice::requestBatteryLevel() 
XDA_DLL_API int XsDevice_setTransportMode(struct XsDevice* thisPtr, int transportModeEnabled);//!< \copydoc XsDevice::setTransportMode(bool) 
XDA_DLL_API int XsDevice_transportMode(struct XsDevice* thisPtr);//!< \copydoc XsDevice::transportMode() 
XDA_DLL_API int16_t XsDevice_lastKnownRssi(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::lastKnownRssi() const 
XDA_DLL_API int XsDevice_isBlueToothEnabled(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isBlueToothEnabled() const 
XDA_DLL_API int XsDevice_setBlueToothEnabled(struct XsDevice* thisPtr, int enabled);//!< \copydoc XsDevice::setBlueToothEnabled(bool) 
XDA_DLL_API int XsDevice_isDualOutputEnabled(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isDualOutputEnabled() const 
XDA_DLL_API int XsDevice_setDualOutputEnabled(struct XsDevice* thisPtr, int enabled);//!< \copydoc XsDevice::setDualOutputEnabled(bool) 
XDA_DLL_API int XsDevice_isBusPowerEnabled(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isBusPowerEnabled() const 
XDA_DLL_API int XsDevice_setBusPowerEnabled(struct XsDevice* thisPtr, int enabled);//!< \copydoc XsDevice::setBusPowerEnabled(bool) 
XDA_DLL_API int XsDevice_powerDown(struct XsDevice* thisPtr);//!< \copydoc XsDevice::powerDown() 
XDA_DLL_API XsErrorMode XsDevice_errorMode(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::errorMode() const 
XDA_DLL_API int XsDevice_setErrorMode(struct XsDevice* thisPtr, XsErrorMode errormode);//!< \copydoc XsDevice::setErrorMode(XsErrorMode) 
XDA_DLL_API int XsDevice_setHeadingOffset(struct XsDevice* thisPtr, double offset);//!< \copydoc XsDevice::setHeadingOffset(double) 
XDA_DLL_API double XsDevice_headingOffset(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::headingOffset() const 
XDA_DLL_API int XsDevice_setLocationId(struct XsDevice* thisPtr, int id);//!< \copydoc XsDevice::setLocationId(int) 
XDA_DLL_API int XsDevice_locationId(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::locationId() const 
XDA_DLL_API XsMatrix* XsDevice_objectAlignment(const struct XsDevice* thisPtr, XsMatrix* returnValue);//!< \copydoc XsDevice::objectAlignment() const 
XDA_DLL_API int XsDevice_setObjectAlignment(struct XsDevice* thisPtr, const XsMatrix* matrix);//!< \copydoc XsDevice::setObjectAlignment(const XsMatrix&) 
XDA_DLL_API XsVector* XsDevice_labMagneticField(const struct XsDevice* thisPtr, XsVector* returnValue);//!< \copydoc XsDevice::labMagneticField() const 
XDA_DLL_API int XsDevice_setLabMagneticField(struct XsDevice* thisPtr, const XsVector* magfield);//!< \copydoc XsDevice::setLabMagneticField(const XsVector&) 
XDA_DLL_API double XsDevice_gravityMagnitude(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::gravityMagnitude() const 
XDA_DLL_API int XsDevice_setGravityMagnitude(struct XsDevice* thisPtr, double mag);//!< \copydoc XsDevice::setGravityMagnitude(double) 
XDA_DLL_API XsVector* XsDevice_latLonAlt(const struct XsDevice* thisPtr, XsVector* returnValue);//!< \copydoc XsDevice::latLonAlt() const 
XDA_DLL_API int XsDevice_setLatLonAlt(struct XsDevice* thisPtr, const XsVector* lla);//!< \copydoc XsDevice::setLatLonAlt(const XsVector&) 
XDA_DLL_API int XsDevice_reinitialize(struct XsDevice* thisPtr);//!< \copydoc XsDevice::reinitialize() 
XDA_DLL_API XsFilterProfile* XsDevice_xdaFilterProfile(const struct XsDevice* thisPtr, XsFilterProfile* returnValue);//!< \copydoc XsDevice::xdaFilterProfile() const 
XDA_DLL_API int XsDevice_setXdaFilterProfile(struct XsDevice* thisPtr, int profileType);//!< \copydoc XsDevice::setXdaFilterProfile(int) 
XDA_DLL_API XsFilterProfile* XsDevice_onboardFilterProfile(const struct XsDevice* thisPtr, XsFilterProfile* returnValue);//!< \copydoc XsDevice::onboardFilterProfile() const 
XDA_DLL_API int XsDevice_setOnboardFilterProfile(struct XsDevice* thisPtr, int profileType);//!< \copydoc XsDevice::setOnboardFilterProfile(int) 
XDA_DLL_API int XsDevice_replaceFilterProfile(struct XsDevice* thisPtr, const XsFilterProfile* profileCurrent, const XsFilterProfile* profileNew);//!< \copydoc XsDevice::replaceFilterProfile(const XsFilterProfile&,const XsFilterProfile&) 
XDA_DLL_API XsFilterProfileArray* XsDevice_availableOnboardFilterProfiles(const struct XsDevice* thisPtr, XsFilterProfileArray* returnValue);//!< \copydoc XsDevice::availableOnboardFilterProfiles() const 
XDA_DLL_API XsFilterProfileArray* XsDevice_availableXdaFilterProfiles(const struct XsDevice* thisPtr, XsFilterProfileArray* returnValue);//!< \copydoc XsDevice::availableXdaFilterProfiles() const 
XDA_DLL_API double XsDevice_accelerometerRange(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::accelerometerRange() const 
XDA_DLL_API double XsDevice_gyroscopeRange(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::gyroscopeRange() const 
XDA_DLL_API int XsDevice_setNoRotation(struct XsDevice* thisPtr, uint16_t duration);//!< \copydoc XsDevice::setNoRotation(uint16_t) 
XDA_DLL_API uint16_t XsDevice_rs485TransmissionDelay(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::rs485TransmissionDelay() const 
XDA_DLL_API int XsDevice_setRs485TransmissionDelay(struct XsDevice* thisPtr, uint16_t delay);//!< \copydoc XsDevice::setRs485TransmissionDelay(uint16_t) 
XDA_DLL_API XsSelfTestResult* XsDevice_runSelfTest(struct XsDevice* thisPtr, XsSelfTestResult* returnValue);//!< \copydoc XsDevice::runSelfTest() 
XDA_DLL_API int XsDevice_requestData(struct XsDevice* thisPtr);//!< \copydoc XsDevice::requestData() 
XDA_DLL_API int XsDevice_storeFilterState(struct XsDevice* thisPtr);//!< \copydoc XsDevice::storeFilterState() 
XDA_DLL_API int XsDevice_isInitialBiasUpdateEnabled(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isInitialBiasUpdateEnabled() const 
XDA_DLL_API int XsDevice_setInitialBiasUpdateEnabled(struct XsDevice* thisPtr, int enable);//!< \copydoc XsDevice::setInitialBiasUpdateEnabled(bool) 
XDA_DLL_API int XsDevice_isFixedGravityEnabled(const struct XsDevice* thisPtr);//!< \copydoc XsDevice::isFixedGravityEnabled() const 
XDA_DLL_API int XsDevice_setFixedGravityEnabled(struct XsDevice* thisPtr, int enable);//!< \copydoc XsDevice::setFixedGravityEnabled(bool) 
XDA_DLL_API XsResultValue XsDevice_createConfigFile(struct XsDevice* thisPtr, const XsString* filename);//!< \copydoc XsDevice::createConfigFile(const XsString&) 
XDA_DLL_API XsResultValue XsDevice_applyConfigFile(struct XsDevice* thisPtr, const XsString* filename);//!< \copydoc XsDevice::applyConfigFile(const XsString&) 
/*! @} */
#ifdef __cplusplus
} // extern "C"
struct XsDevice {
	inline XsDevice* master(void) const
	{
		return XsDevice_master(this);
	}

	inline XsDevicePtrArray children(void) const
	{
		XsDevicePtrArray returnValue;
		return *XsDevice_children(this, &returnValue);
	}

	inline XsDevice* findDevice(XsDeviceId deviceid) const
	{
		return XsDevice_findDevice(this, deviceid);
	}

	inline int busId(void) const
	{
		return XsDevice_busId(this);
	}

	inline XsDeviceId deviceId(void) const
	{
		XsDeviceId returnValue;
		return *XsDevice_deviceId(this, &returnValue);
	}

	inline XsVersion firmwareVersion(void) const
	{
		XsVersion returnValue;
		return *XsDevice_firmwareVersion(this, &returnValue);
	}

	inline bool isMasterDevice(void) const
	{
		return 0 != XsDevice_isMasterDevice(this);
	}

	inline bool isInitialized(void) const
	{
		return 0 != XsDevice_isInitialized(this);
	}

	inline const XsDevice* deviceAtBusId(int busid) const
	{
		return XsDevice_deviceAtBusId(this, busid);
	}

	inline XsDevice* deviceAtBusId(int busid)
	{
		return XsDevice_deviceAtBusId_1(this, busid);
	}

	inline void setGotoConfigOnClose(bool gotoConfigOnClose)
	{
		XsDevice_setGotoConfigOnClose(this, gotoConfigOnClose);
	}

	inline XsResultValue createLogFile(const XsString& filename)
	{
		return XsDevice_createLogFile(this, &filename);
	}

	inline bool closeLogFile(void)
	{
		return 0 != XsDevice_closeLogFile(this);
	}

	inline bool isMeasuring(void) const
	{
		return 0 != XsDevice_isMeasuring(this);
	}

	inline bool isRecording(void) const
	{
		return 0 != XsDevice_isRecording(this);
	}

	inline bool isReadingFromFile(void) const
	{
		return 0 != XsDevice_isReadingFromFile(this);
	}

	inline void restartFilter(void)
	{
		XsDevice_restartFilter(this);
	}

	inline int queueLength(void) const
	{
		return XsDevice_queueLength(this);
	}

	inline XsDeviceState deviceState(void) const
	{
		return XsDevice_deviceState(this);
	}

	inline XsDataPacket nextAvailableDataPacket(void)
	{
		XsDataPacket returnValue;
		return *XsDevice_nextAvailableDataPacket(this, &returnValue);
	}

	inline XsDataPacket dataPacketByIndex(uint32_t index)
	{
		XsDataPacket returnValue;
		return *XsDevice_dataPacketByIndex(this, &returnValue, index);
	}

	inline XsDataPacket dataPacketById(uint64_t packetId)
	{
		XsDataPacket returnValue;
		return *XsDevice_dataPacketById(this, &returnValue, packetId);
	}

	inline void clearCallbackHandlers(bool chain = true)
	{
		XsDevice_clearCallbackHandlers(this, chain);
	}

	inline void addCallbackHandler(XsCallbackPlainC* cb, bool chain = true)
	{
		XsDevice_addCallbackHandler(this, cb, chain);
	}

	inline void removeCallbackHandler(XsCallbackPlainC* cb, bool chain = true)
	{
		XsDevice_removeCallbackHandler(this, cb, chain);
	}

	inline XsDeviceConfiguration deviceConfiguration(void) const
	{
		XsDeviceConfiguration returnValue;
		return *XsDevice_deviceConfiguration(this, &returnValue);
	}

	inline void clear(void)
	{
		XsDevice_clear(this);
	}

	inline int batteryLevel(void) const
	{
		return XsDevice_batteryLevel(this);
	}

	inline int updateRateForDataIdentifier(XsDataIdentifier dataType) const
	{
		return XsDevice_updateRateForDataIdentifier(this, dataType);
	}

	inline int updateRateForProcessedDataIdentifier(XsDataIdentifier dataType) const
	{
		return XsDevice_updateRateForProcessedDataIdentifier(this, dataType);
	}

	inline XsIntArray supportedUpdateRates(XsDataIdentifier dataType = XDI_None) const
	{
		XsIntArray returnValue;
		return *XsDevice_supportedUpdateRates(this, &returnValue, dataType);
	}

	inline int maximumUpdateRate(void) const
	{
		return XsDevice_maximumUpdateRate(this);
	}

	inline bool hasDataEnabled(XsDataIdentifier dataType) const
	{
		return 0 != XsDevice_hasDataEnabled(this, dataType);
	}

	inline bool hasProcessedDataEnabled(XsDataIdentifier dataType) const
	{
		return 0 != XsDevice_hasProcessedDataEnabled(this, dataType);
	}

	inline XsString productCode(void) const
	{
		XsString returnValue;
		return *XsDevice_productCode(this, &returnValue);
	}

	inline XsString portName(void) const
	{
		XsString returnValue;
		return *XsDevice_portName(this, &returnValue);
	}

	inline XsBaudRate baudRate(void) const
	{
		XsBaudRate returnValue;
		return *XsDevice_baudRate(this, &returnValue);
	}

	inline XsBaudRate serialBaudRate(void) const
	{
		XsBaudRate returnValue;
		return *XsDevice_serialBaudRate(this, &returnValue);
	}

	inline XsVersion hardwareVersion(void) const
	{
		XsVersion returnValue;
		return *XsDevice_hardwareVersion(this, &returnValue);
	}

	inline bool startRecording(void)
	{
		return 0 != XsDevice_startRecording(this);
	}

	inline bool stopRecording(void)
	{
		return 0 != XsDevice_stopRecording(this);
	}

	inline bool setOptionEnabled(XsOption option, bool enabled)
	{
		return 0 != XsDevice_setOptionEnabled(this, option, enabled);
	}

	inline bool isOptionEnabled(XsOption option) const
	{
		return 0 != XsDevice_isOptionEnabled(this, option);
	}

	inline bool initializeFilter(void)
	{
		return 0 != XsDevice_initializeFilter(this);
	}

	inline bool sendCustomMessage(const XsMessage& messageSend, bool waitForResult, XsMessage& messageReceive, int timeout = 0)
	{
		return 0 != XsDevice_sendCustomMessage(this, &messageSend, waitForResult, &messageReceive, timeout);
	}

	inline bool sendRawMessage(const XsMessage& message)
	{
		return 0 != XsDevice_sendRawMessage(this, &message);
	}

	inline bool setSerialBaudRate(XsBaudRate baudrate)
	{
		return 0 != XsDevice_setSerialBaudRate(this, baudrate);
	}

	inline bool isMotionTracker(void) const
	{
		return 0 != XsDevice_isMotionTracker(this);
	}

	inline XsOutputMode outputMode(void) const
	{
		return XsDevice_outputMode(this);
	}

	inline bool setOutputMode(XsOutputMode mode)
	{
		return 0 != XsDevice_setOutputMode(this, mode);
	}

	inline XsOutputSettings outputSettings(void) const
	{
		return XsDevice_outputSettings(this);
	}

	inline bool setOutputSettings(XsOutputSettings outputsettings)
	{
		return 0 != XsDevice_setOutputSettings(this, outputsettings);
	}

	inline int updateRate(void) const
	{
		return XsDevice_updateRate(this);
	}

	inline bool setUpdateRate(int rate)
	{
		return 0 != XsDevice_setUpdateRate(this, rate);
	}

	inline XsOutputConfigurationArray outputConfiguration(void) const
	{
		XsOutputConfigurationArray returnValue;
		return *XsDevice_outputConfiguration(this, &returnValue);
	}

	inline XsOutputConfigurationArray processedOutputConfiguration(void) const
	{
		XsOutputConfigurationArray returnValue;
		return *XsDevice_processedOutputConfiguration(this, &returnValue);
	}

	inline bool setOutputConfiguration(XsOutputConfigurationArray& config)
	{
		return 0 != XsDevice_setOutputConfiguration(this, &config);
	}

	inline bool isInLegacyMode(void) const
	{
		return 0 != XsDevice_isInLegacyMode(this);
	}

	inline uint16_t samplePeriod(void) const
	{
		return XsDevice_samplePeriod(this);
	}

	inline bool setSamplePeriod(uint16_t period)
	{
		return 0 != XsDevice_setSamplePeriod(this, period);
	}

	inline uint16_t outputSkipFactor(void) const
	{
		return XsDevice_outputSkipFactor(this);
	}

	inline bool setOutputSkipFactor(uint16_t skipFactor)
	{
		return 0 != XsDevice_setOutputSkipFactor(this, skipFactor);
	}

	inline XsDeviceMode deviceMode(void) const
	{
		XsDeviceMode returnValue;
		return *XsDevice_deviceMode(this, &returnValue);
	}

	inline bool setDeviceMode(const XsDeviceMode& mode)
	{
		return 0 != XsDevice_setDeviceMode(this, &mode);
	}

	inline int dataLength(void) const
	{
		return XsDevice_dataLength(this);
	}

	inline void clearCache(void)
	{
		XsDevice_clearCache(this);
	}

	inline XsSyncSettingArray syncSettings(void) const
	{
		XsSyncSettingArray returnValue;
		return *XsDevice_syncSettings(this, &returnValue);
	}

	inline bool setSyncSettings(const XsSyncSettingArray& settingList)
	{
		return 0 != XsDevice_setSyncSettings(this, &settingList);
	}

	inline bool isSyncMaster(void) const
	{
		return 0 != XsDevice_isSyncMaster(this);
	}

	inline bool isSyncSlave(void) const
	{
		return 0 != XsDevice_isSyncSlave(this);
	}

	inline XsSyncSettingArray supportedSyncSettings(void) const
	{
		XsSyncSettingArray returnValue;
		return *XsDevice_supportedSyncSettings(this, &returnValue);
	}

	inline bool gotoMeasurement(void)
	{
		return 0 != XsDevice_gotoMeasurement(this);
	}

	inline bool gotoConfig(void)
	{
		return 0 != XsDevice_gotoConfig(this);
	}

	inline bool restoreFactoryDefaults(void)
	{
		return 0 != XsDevice_restoreFactoryDefaults(this);
	}

	inline bool reset(void)
	{
		return 0 != XsDevice_reset(this);
	}

	inline void writeDeviceSettingsToFile(void)
	{
		XsDevice_writeDeviceSettingsToFile(this);
	}

	inline void flushInputBuffers(bool complete)
	{
		XsDevice_flushInputBuffers(this, complete);
	}

	inline XsSyncRole syncRole(void) const
	{
		return XsDevice_syncRole(this);
	}

	inline bool loadLogFile(void)
	{
		return 0 != XsDevice_loadLogFile(this);
	}

	inline bool abortLoadLogFile(void)
	{
		return 0 != XsDevice_abortLoadLogFile(this);
	}

	inline XsString logFileName(void) const
	{
		XsString returnValue;
		return *XsDevice_logFileName(this, &returnValue);
	}

	inline int droppedPacketCount(void) const
	{
		return XsDevice_droppedPacketCount(this);
	}

	inline bool resetOrientation(XsResetMethod resetmethod)
	{
		return 0 != XsDevice_resetOrientation(this, resetmethod);
	}

	inline XsXbusMessageId peekMessageId(void)
	{
		return XsDevice_peekMessageId(this);
	}

	inline bool resetLogFileReadPosition(void)
	{
		return 0 != XsDevice_resetLogFileReadPosition(this);
	}

	inline XsFilePos logFileSize(void) const
	{
		return XsDevice_logFileSize(this);
	}

	inline XsFilePos logFileReadPosition(void) const
	{
		return XsDevice_logFileReadPosition(this);
	}

	inline bool updateCachedDeviceInformation(void)
	{
		return 0 != XsDevice_updateCachedDeviceInformation(this);
	}

	inline bool resetDroppedPacketCount(void)
	{
		return 0 != XsDevice_resetDroppedPacketCount(this);
	}

	inline bool setQueueMode(XsQueueMode mode)
	{
		return 0 != XsDevice_setQueueMode(this, mode);
	}

	inline XsQueueMode queueMode(void) const
	{
		return XsDevice_queueMode(this);
	}

	inline XsConnectivityState connectivityState(void) const
	{
		XsConnectivityState returnValue;
		return *XsDevice_connectivityState(this, &returnValue);
	}

	inline bool enableRadio(int channel)
	{
		return 0 != XsDevice_enableRadio(this, channel);
	}

	inline bool disableRadio(void)
	{
		return 0 != XsDevice_disableRadio(this);
	}

	inline int radioChannel(void) const
	{
		return XsDevice_radioChannel(this);
	}

	inline bool isRadioEnabled(void) const
	{
		return 0 != XsDevice_isRadioEnabled(this);
	}

	inline bool makeOperational(void)
	{
		return 0 != XsDevice_makeOperational(this);
	}

	inline bool isOperational(void) const
	{
		return 0 != XsDevice_isOperational(this);
	}

	inline bool abortFlushing(void)
	{
		return 0 != XsDevice_abortFlushing(this);
	}

	inline bool setDeviceAccepted(const XsDeviceId& deviceId)
	{
		return 0 != XsDevice_setDeviceAccepted(this, &deviceId);
	}

	inline bool setDeviceRejected(const XsDeviceId& deviceId)
	{
		return 0 != XsDevice_setDeviceRejected(this, &deviceId);
	}

	inline bool acceptConnection(void)
	{
		return 0 != XsDevice_acceptConnection(this);
	}

	inline bool rejectConnection(void)
	{
		return 0 != XsDevice_rejectConnection(this);
	}

	inline int wirelessPriority(void) const
	{
		return XsDevice_wirelessPriority(this);
	}

	inline bool setWirelessPriority(int priority)
	{
		return 0 != XsDevice_setWirelessPriority(this, priority);
	}

	inline XsRejectReason rejectReason(void) const
	{
		return XsDevice_rejectReason(this);
	}

	inline bool requestBatteryLevel(void)
	{
		return 0 != XsDevice_requestBatteryLevel(this);
	}

	inline bool setTransportMode(bool transportModeEnabled)
	{
		return 0 != XsDevice_setTransportMode(this, transportModeEnabled);
	}

	inline bool transportMode(void)
	{
		return 0 != XsDevice_transportMode(this);
	}

	inline int16_t lastKnownRssi(void) const
	{
		return XsDevice_lastKnownRssi(this);
	}

	inline bool isBlueToothEnabled(void) const
	{
		return 0 != XsDevice_isBlueToothEnabled(this);
	}

	inline bool setBlueToothEnabled(bool enabled)
	{
		return 0 != XsDevice_setBlueToothEnabled(this, enabled);
	}

	inline bool isDualOutputEnabled(void) const
	{
		return 0 != XsDevice_isDualOutputEnabled(this);
	}

	inline bool setDualOutputEnabled(bool enabled)
	{
		return 0 != XsDevice_setDualOutputEnabled(this, enabled);
	}

	inline bool isBusPowerEnabled(void) const
	{
		return 0 != XsDevice_isBusPowerEnabled(this);
	}

	inline bool setBusPowerEnabled(bool enabled)
	{
		return 0 != XsDevice_setBusPowerEnabled(this, enabled);
	}

	inline bool powerDown(void)
	{
		return 0 != XsDevice_powerDown(this);
	}

	inline XsErrorMode errorMode(void) const
	{
		return XsDevice_errorMode(this);
	}

	inline bool setErrorMode(XsErrorMode errormode)
	{
		return 0 != XsDevice_setErrorMode(this, errormode);
	}

	inline bool setHeadingOffset(double offset)
	{
		return 0 != XsDevice_setHeadingOffset(this, offset);
	}

	inline double headingOffset(void) const
	{
		return XsDevice_headingOffset(this);
	}

	inline bool setLocationId(int id)
	{
		return 0 != XsDevice_setLocationId(this, id);
	}

	inline int locationId(void) const
	{
		return XsDevice_locationId(this);
	}

	inline XsMatrix objectAlignment(void) const
	{
		XsMatrix returnValue;
		return *XsDevice_objectAlignment(this, &returnValue);
	}

	inline bool setObjectAlignment(const XsMatrix& matrix)
	{
		return 0 != XsDevice_setObjectAlignment(this, &matrix);
	}

	inline XsVector labMagneticField(void) const
	{
		XsVector returnValue;
		return *XsDevice_labMagneticField(this, &returnValue);
	}

	inline bool setLabMagneticField(const XsVector& magfield)
	{
		return 0 != XsDevice_setLabMagneticField(this, &magfield);
	}

	inline double gravityMagnitude(void) const
	{
		return XsDevice_gravityMagnitude(this);
	}

	inline bool setGravityMagnitude(double mag)
	{
		return 0 != XsDevice_setGravityMagnitude(this, mag);
	}

	inline XsVector latLonAlt(void) const
	{
		XsVector returnValue;
		return *XsDevice_latLonAlt(this, &returnValue);
	}

	inline bool setLatLonAlt(const XsVector& lla)
	{
		return 0 != XsDevice_setLatLonAlt(this, &lla);
	}

	inline bool reinitialize(void)
	{
		return 0 != XsDevice_reinitialize(this);
	}

	inline XsFilterProfile xdaFilterProfile(void) const
	{
		XsFilterProfile returnValue;
		return *XsDevice_xdaFilterProfile(this, &returnValue);
	}

	inline bool setXdaFilterProfile(int profileType)
	{
		return 0 != XsDevice_setXdaFilterProfile(this, profileType);
	}

	inline XsFilterProfile onboardFilterProfile(void) const
	{
		XsFilterProfile returnValue;
		return *XsDevice_onboardFilterProfile(this, &returnValue);
	}

	inline bool setOnboardFilterProfile(int profileType)
	{
		return 0 != XsDevice_setOnboardFilterProfile(this, profileType);
	}

	inline bool replaceFilterProfile(const XsFilterProfile& profileCurrent, const XsFilterProfile& profileNew)
	{
		return 0 != XsDevice_replaceFilterProfile(this, &profileCurrent, &profileNew);
	}

	inline XsFilterProfileArray availableOnboardFilterProfiles(void) const
	{
		XsFilterProfileArray returnValue;
		return *XsDevice_availableOnboardFilterProfiles(this, &returnValue);
	}

	inline XsFilterProfileArray availableXdaFilterProfiles(void) const
	{
		XsFilterProfileArray returnValue;
		return *XsDevice_availableXdaFilterProfiles(this, &returnValue);
	}

	inline double accelerometerRange(void) const
	{
		return XsDevice_accelerometerRange(this);
	}

	inline double gyroscopeRange(void) const
	{
		return XsDevice_gyroscopeRange(this);
	}

	inline bool setNoRotation(uint16_t duration)
	{
		return 0 != XsDevice_setNoRotation(this, duration);
	}

	inline uint16_t rs485TransmissionDelay(void) const
	{
		return XsDevice_rs485TransmissionDelay(this);
	}

	inline bool setRs485TransmissionDelay(uint16_t delay)
	{
		return 0 != XsDevice_setRs485TransmissionDelay(this, delay);
	}

	inline XsSelfTestResult runSelfTest(void)
	{
		XsSelfTestResult returnValue;
		return *XsDevice_runSelfTest(this, &returnValue);
	}

	inline bool requestData(void)
	{
		return 0 != XsDevice_requestData(this);
	}

	inline bool storeFilterState(void)
	{
		return 0 != XsDevice_storeFilterState(this);
	}

	inline bool isInitialBiasUpdateEnabled(void) const
	{
		return 0 != XsDevice_isInitialBiasUpdateEnabled(this);
	}

	inline bool setInitialBiasUpdateEnabled(bool enable)
	{
		return 0 != XsDevice_setInitialBiasUpdateEnabled(this, enable);
	}

	inline bool isFixedGravityEnabled(void) const
	{
		return 0 != XsDevice_isFixedGravityEnabled(this);
	}

	inline bool setFixedGravityEnabled(bool enable)
	{
		return 0 != XsDevice_setFixedGravityEnabled(this, enable);
	}

	inline XsResultValue createConfigFile(const XsString& filename)
	{
		return XsDevice_createConfigFile(this, &filename);
	}

	inline XsResultValue applyConfigFile(const XsString& filename)
	{
		return XsDevice_applyConfigFile(this, &filename);
	}

private:
	XsDevice(); //!< \protectedsection \brief Default constructor not implemented to prevent faulty memory allocation, use construct() function instead
	~XsDevice(); //!< \brief Destructor not implemented, use destruct() function instead
	void* operator new (size_t); //!< \protectedsection \brief new operator not implemented to prevent faulty memory allocation by user, use construct() function instead
	void* operator new[] (size_t); //!< \protectedsection \brief array new operator not implemented to prevent faulty memory allocation by user, use construct() function instead
	void operator delete (void*); //!< \protectedsection \brief delete operator not implemented to prevent faulty memory deallocation by user, use destruct() function instead
	void operator delete[] (void*); //!< \protectedsection \brief array delete operator not implemented to prevent faulty memory deallocation by user, use destruct() function instead
};
#endif // __cplusplus
#endif // GUARD_XSDEVICE_H
