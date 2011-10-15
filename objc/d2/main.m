/******************* hello.m ***********************/
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

@interface HelloWorld : NSObject
- (void) hello;
@end

@implementation HelloWorld
- (void) hello {
    NSLog(@"hello world!");
}   
@end

int main(int argc, const char *argv[])
{
    HelloWorld *hw = [HelloWorld alloc];
    [hw hello];
    
    //    NSWindow *window = [NSWindow alloc];
    //    NSButton *button = [NSButton alloc];

    return NSApplicationMain(argc, argv);
}

