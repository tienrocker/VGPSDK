#
#  Be sure to run `pod spec lint HelloWorld.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#
Pod::Spec.new do |s|
# ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #
s.name          = 'VGPSDK'
  s.version       = '3.10.0'
  s.summary       = 'iOS SDK for VGP partner'
  s.homepage      = 'https://github.com/tienrocker/'
  s.description   = 'iOS SDK framework which has a logger class and game base function'
  s.license       = 'MIT'
  s.author        = { 'James Tran' => 'tienrocker@gmail.com' }
  s.platform      = :ios, '10.0'
  s.ios.vendored_frameworks = 'VGPSDK.framework'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'ONLY_ACTIVE_ARCH' => 'NO' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'ONLY_ACTIVE_ARCH' => 'NO' }
  s.source        = { :git => 'https://github.com/tienrocker/VGPSDK.git', :tag => s.version.to_s }

  s.swift_versions = ['4.0']
  s.public_header_files = "VGPSDK.framework/Headers/*.h"
  
  # s.static_framework = true
  s.ios.deployment_target = '10.0'

  s.frameworks = 'UIKit'
  
  s.dependency 'FBSDKCoreKit', '8.2.0'
  s.dependency 'FBSDKLoginKit', '8.2.0'
  s.dependency 'FBSDKShareKit', '8.2.0'
  
  s.dependency 'Firebase/Analytics', '7.7.0'
  s.dependency 'Firebase/Messaging', '7.7.0'
  s.dependency 'Firebase/Crashlytics', '7.7.0'
  s.dependency 'Google-Mobile-Ads-SDK', '8.1.0'

  s.dependency 'AppsFlyerFramework', '6.2.2'
  
  s.dependency 'AFNetworking', '4.0.1'
  s.dependency 'FCUUID', '1.3.1'

end
