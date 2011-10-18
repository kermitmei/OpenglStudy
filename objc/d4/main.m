#import <Foundation/Foundation.h>

int main(int argc, const char *argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    
    NSMutableArray *array;
    array = [[NSMutableArray alloc] init];
    int i;
    for(i = 0; i < 10; ++i) {
	NSNumber *newNumber = [[NSNumber alloc] initWithInt:(i*3)];
	[array addObject:newNumber];
    }

    for(i = 0; i < 10; ++i) {
	NSNumber *numberToPrint = [array objectAtIndex:i];
	NSLog(@"The number at index %d is %@", i, numberToPrint);
    }

    [pool drain];

    return 0;
}
