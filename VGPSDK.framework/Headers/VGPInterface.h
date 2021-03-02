//
//  VGPInterface.h
//  VGPSDK
//
//  Created by  Tien Tran on 2/3/20.
//  Copyright © 2020  Tien Tran. All rights reserved.
//

#ifndef VGPInterface_h
#define VGPInterface_h

#import <UIKit/UIKit.h>
#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <FBSDKLoginKit/FBSDKLoginKit.h>
#import <FBSDKShareKit/FBSDKShareKit.h>
#import <FBSDKShareKit/FBSDKShareDialog.h>
#import <FBSDKShareKit/FBSDKShareLinkContent.h>
#import <FBSDKShareKit/FBSDKSharePhoto.h>
#import <FBSDKShareKit/FBSDKSharePhotoContent.h>
#import <AppsFlyerLib/AppsFlyerLib.h>
#import <AppTrackingTransparency/ATTrackingManager.h>
@import Firebase;
@import GoogleMobileAds;

@class VGPInterface;

@interface VGPInterface : UIResponder <UIApplicationDelegate, AppsFlyerLibDelegate, UNUserNotificationCenterDelegate, FIRMessagingDelegate>

+ (VGPInterface *_Nonnull)sharedInstance;

#pragma mark -  Data
- (NSInteger)getUserID;
- (NSString *_Nullable)getUsername;

#pragma mark -  Handler User Interface
- (void)changeLocalization:(NSString *_Nonnull)localization;
- (void)loginGame;
- (void)loginGame:(void (^ __nullable)(void))completion;
- (void)purchase:(NSString *_Nonnull)characterID serverID:(NSString *_Nonnull)serverID itemID:(NSString *_Nonnull)itemID andPartnerData:(NSString *_Nullable)partnerData;
- (void)logoutGame;
- (void)logoutGame:(void (^ __nullable)(void))completion;
- (void)showProfile;
- (void)showProfile:(void (^ __nullable)(void))completion;
- (void)showFlyButton;
- (void)showFlyButton:(void (^ __nullable)(void))completion;
- (void)hideFlyButton;

#pragma mark -  Marketing Events

- (void)setGameVersion:(NSString*_Nonnull)code;
- (void)setGameCode:(NSString*_Nonnull)code;

- (void)logCreatedCharacter;
- (void)logLevelUp:(int) level;
// PAYMENT FORM
- (void)logOpenPaymentScreen;
- (void)logPurchase:(int) money;
// DOWNLOAD RESOURCE
- (void)logStartDownloadResource;
- (void)logDownloadResourcePercent:(int)percent;
- (void)logDownloadResourceSuccess;
- (void)logDownloadResourceFail;
// EXTRACT RESOURCE
- (void)logStartExtractResource;
- (void)logExtractResourceSuccess;
- (void)logExtractResourceFail;
// GAME VERSION
- (void)logStartCheckGameVersionClient;
- (void)logCheckGameVersionClientSuccess;
- (void)logCheckGameVersionClientFail;
// SERVER LIST
- (void)logStartGetGameServerList;
- (void)logGetGameServerListSuccess;
- (void)logGetGameServerListFail;
// SERVER CONFIG
- (void)logStartGetServerConfig;
- (void)logGetServerConfigSuccess;
- (void)logGetServerConfigFail;

- (void)shareFacebookImage:(NSString *_Nonnull)url;
- (void)shareFacebookImageLocal:(UIImage *_Nonnull)image;

#pragma mark -  Init Application
- (BOOL)application:(UIApplication *_Nonnull)application didFinishLaunchingWithOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions API_AVAILABLE(ios(3.0));
- (void)applicationDidBecomeActive:(UIApplication *_Nonnull)application;
// Deep linking
// Open URI-scheme for iOS 9 and above
- (BOOL)application:(UIApplication *_Nonnull)application openURL:(NSURL *_Nullable)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *_Nullable)options;
// Open URI-scheme for iOS 8 and below
- (BOOL)application:(UIApplication *_Nonnull)application openURL:(NSURL *_Nullable)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id _Nullable )annotation;
// Open Universal Links
- (BOOL)application:(UIApplication *_Nonnull)application continueUserActivity:(NSUserActivity *_Nullable)userActivity restorationHandler:(void (^_Nullable)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler;
- (void)application:(UIApplication *_Nonnull)application didChangeStatusBarOrientation:(UIInterfaceOrientation)oldStatusBarOrientation;
- (void)scene:(UIScene *_Nonnull)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions  API_AVAILABLE(ios(13.0));
- (void)scene:(UIScene *_Nonnull)scene openURLContexts:(NSSet<UIOpenURLContext *> *_Nonnull)URLContexts  API_AVAILABLE(ios(13.0));
- (void)scene:(UIScene *_Nonnull)scene continueUserActivity:(NSUserActivity *_Nonnull)userActivity  API_AVAILABLE(ios(13.0));
- (void)sceneDidBecomeActive:(UIScene *_Nullable)scene  API_AVAILABLE(ios(13.0));
- (void)application:(UIApplication *_Nullable)application didReceiveRemoteNotification:(NSDictionary *_Nullable)userInfo
fetchCompletionHandler:(void (^_Nullable)(UIBackgroundFetchResult))completionHandler;

#pragma mark -  Register Push notification
- (void)application:(UIApplication*_Nonnull)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*_Nonnull)deviceToken;
- (void)application:(UIApplication*_Nonnull)application didFailToRegisterForRemoteNotificationsWithError:(NSError*_Nonnull)error;

@end

#endif /* VGPInterface_h */
