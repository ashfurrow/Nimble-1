//
//  Created by marco on 10/07/13.
//
//
//


#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, NimbleContextType) {
  NimbleMainContext = 0,
  NimbleBackgroundContext = 1
};

extern NSString *const NBStoreGotReplacedByCloudStore;

// let's try not to get crazy
typedef void (^NimbleSimpleBlock)(NimbleContextType contextType);
typedef void (^NimbleErrorBlock)(NSError *error);

@interface NimbleStore : NSObject

+ (void)nb_setupInMemoryStore;
+ (void)nb_setupStore;
+ (void)nb_setupStoreWithFilename:(NSString *)filename;
+ (void)nb_setupStoreWithName:(NSString *)filename storeType:(NSString * const)storeType iCloudEnabled:(BOOL)iCloudEnabled options:(NSDictionary *)options;

/**
* Execute a fetch request in one of the contexts
*
*/
+ (NSArray *)nb_executeFetchRequest:(NSFetchRequest *)request inContextOfType:(NimbleContextType)contextType;

+ (NSManagedObjectContext *)nb_mainContext;
+ (NSManagedObjectContext *)nb_backgroundContext;
+ (NSOperationQueue *)nb_queueForBackgroundSavings;

@end