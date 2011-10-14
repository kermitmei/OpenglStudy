/******************* hello.m ***********************/
#import <Foundation/Foundation.h>

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
    NSMutableArray *foo;
    foo = [NSMutableArray alloc];
    printf("Hello, world!\n");
    return 0;
}

