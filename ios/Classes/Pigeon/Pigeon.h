// Autogenerated from Pigeon (v7.0.0), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#import <Foundation/Foundation.h>

@protocol FlutterBinaryMessenger;
@protocol FlutterMessageCodec;
@class FlutterError;
@class FlutterStandardTypedData;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PigeonSensorType) {
  /// A built-in wide-angle camera.
  ///
  /// The wide angle sensor is the default sensor for iOS
  PigeonSensorTypeWideAngle = 0,
  /// A built-in camera with a shorter focal length than that of the wide-angle camera.
  PigeonSensorTypeUltraWideAngle = 1,
  /// A built-in camera device with a longer focal length than the wide-angle camera.
  PigeonSensorTypeTelephoto = 2,
  /// A device that consists of two cameras, one Infrared and one YUV.
  ///
  /// iOS only
  PigeonSensorTypeTrueDepth = 3,
  PigeonSensorTypeUnknown = 4,
};

typedef NS_ENUM(NSUInteger, CamerAwesomePermission) {
  CamerAwesomePermissionStorage = 0,
  CamerAwesomePermissionCamera = 1,
  CamerAwesomePermissionLocation = 2,
  CamerAwesomePermissionRecord_audio = 3,
};

@class PreviewSize;
@class ExifPreferences;
@class VideoOptions;
@class PigeonSensorTypeDevice;

@interface PreviewSize : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithWidth:(NSNumber *)width
    height:(NSNumber *)height;
@property(nonatomic, strong) NSNumber * width;
@property(nonatomic, strong) NSNumber * height;
@end

@interface ExifPreferences : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithSaveGPSLocation:(NSNumber *)saveGPSLocation;
@property(nonatomic, strong) NSNumber * saveGPSLocation;
@end

@interface VideoOptions : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithFileType:(NSString *)fileType
    codec:(NSString *)codec;
@property(nonatomic, copy) NSString * fileType;
@property(nonatomic, copy) NSString * codec;
@end

@interface PigeonSensorTypeDevice : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithSensorType:(PigeonSensorType)sensorType
    name:(NSString *)name
    iso:(NSNumber *)iso
    flashAvailable:(NSNumber *)flashAvailable
    uid:(NSString *)uid;
@property(nonatomic, assign) PigeonSensorType sensorType;
/// A localized device name for display in the user interface.
@property(nonatomic, copy) NSString * name;
/// The current exposure ISO value.
@property(nonatomic, strong) NSNumber * iso;
/// A Boolean value that indicates whether the flash is currently available for use.
@property(nonatomic, strong) NSNumber * flashAvailable;
/// An identifier that uniquely identifies the device.
@property(nonatomic, copy) NSString * uid;
@end

/// The codec used by CameraInterface.
NSObject<FlutterMessageCodec> *CameraInterfaceGetCodec(void);

@protocol CameraInterface
- (void)setupCameraSensor:(NSString *)sensor aspectRatio:(NSString *)aspectRatio zoom:(NSNumber *)zoom flashMode:(NSString *)flashMode captureMode:(NSString *)captureMode enableImageStream:(NSNumber *)enableImageStream exifPreferences:(ExifPreferences *)exifPreferences completion:(void(^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// @return `nil` only when `error != nil`.
- (nullable NSArray<NSString *> *)checkPermissionsWithError:(FlutterError *_Nullable *_Nonnull)error;
/// Returns given [CamerAwesomePermission] list (as String). Location permission might be
/// refused but the app should still be able to run.
- (void)requestPermissionsSaveGpsLocation:(NSNumber *)saveGpsLocation completion:(void(^)(NSArray<NSString *> *_Nullable, FlutterError *_Nullable))completion;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)getPreviewTextureIdWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)takePhotoPath:(NSString *)path completion:(void(^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
- (void)recordVideoPath:(NSString *)path options:(nullable VideoOptions *)options completion:(void(^)(FlutterError *_Nullable))completion;
- (void)pauseVideoRecordingWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)resumeVideoRecordingWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)receivedImageFromStreamWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)stopRecordingVideoWithCompletion:(void(^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// @return `nil` only when `error != nil`.
- (nullable NSArray<PigeonSensorTypeDevice *> *)getFrontSensorsWithError:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSArray<PigeonSensorTypeDevice *> *)getBackSensorsWithError:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)startWithError:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)stopWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)setFlashModeMode:(NSString *)mode error:(FlutterError *_Nullable *_Nonnull)error;
- (void)handleAutoFocusWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)focusOnPointPreviewSize:(PreviewSize *)previewSize x:(NSNumber *)x y:(NSNumber *)y error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setZoomZoom:(NSNumber *)zoom error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setSensorSensor:(NSString *)sensor deviceId:(nullable NSString *)deviceId error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setCorrectionBrightness:(NSNumber *)brightness error:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)getMaxZoomWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)setCaptureModeMode:(NSString *)mode error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setRecordingAudioModeEnableAudio:(NSNumber *)enableAudio completion:(void(^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// @return `nil` only when `error != nil`.
- (nullable NSArray<PreviewSize *> *)availableSizesWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)refreshWithError:(FlutterError *_Nullable *_Nonnull)error;
- (nullable PreviewSize *)getEffectivPreviewSizeWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)setPhotoSizeSize:(PreviewSize *)size error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setPreviewSizeSize:(PreviewSize *)size error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setAspectRatioAspectRatio:(NSString *)aspectRatio error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setupImageAnalysisStreamFormat:(NSString *)format width:(NSNumber *)width maxFramesPerSecond:(nullable NSNumber *)maxFramesPerSecond autoStart:(NSNumber *)autoStart error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setExifPreferencesExifPreferences:(ExifPreferences *)exifPreferences completion:(void(^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
- (void)startAnalysisWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)stopAnalysisWithError:(FlutterError *_Nullable *_Nonnull)error;
@end

extern void CameraInterfaceSetup(id<FlutterBinaryMessenger> binaryMessenger, NSObject<CameraInterface> *_Nullable api);

NS_ASSUME_NONNULL_END