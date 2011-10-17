#import <Foundation/Foundation.h>
#import "LotteryEntry.h"

int main(int argc, const char *argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    //创建数据对象
    NSCalendarDate *now = [[NSCalendarDate alloc] init];
    
    //产生一个随机数生成器
    srandom(time(NULL));
    NSMutableArray *array;
    array = [[NSMutableArray alloc] init];

    int i;
    for (i = 0; i < 10; i++) {
	//产生一个距离现在"i" 星期后的日期
	NSCalendarDate *iWeeksFromNow;
	iWeeksFromNow = [now dateByAddingYears:0
					months:0
					  days:(i*7)
					 hours:0
				       minutes:0
				       seconds:0];

	//创建一个新的LotteryEntry实例
	LotteryEntry *newEntry = [[LotteryEntry alloc] init];
	[newEntry prepareRandomNumbers];
	[newEntry setEntryDate:iWeeksFromNow];
	
	//将LotteryEntry对象添加到数组中
	[array addObject:newEntry];
    }

    for (LotteryEntry *entryToPrint in array) {
	//显示其中内容
	NSLog(@"%@", entryToPrint);
    }

    [pool drain];
    return 0;
}
