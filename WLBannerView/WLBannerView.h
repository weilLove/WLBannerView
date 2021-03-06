//
//  WLBannerView.h
//  WLBannerViewDemo
//
//  Created by weil on 2019/12/31.
//  Copyright © 2019 AllYoga. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class WLBannerView;
@protocol WLBannerViewDelegate <NSObject>
@optional
- (void) bannerView:(WLBannerView *)bannerView didScrollToIndex:(NSUInteger)index;
- (void) bannerView:(WLBannerView *)bannerView willScrollToIndex:(NSUInteger)index fromIndex:(NSUInteger)fromIndex;
- (void) bannerViewDidScroll:(WLBannerView *)bannerView;
- (void) bannerViewWillDragging:(WLBannerView *)bannerView;
- (void) bannerViewDidEndDragging:(WLBannerView *)bannerView;
- (void) bannerViewDidEndDelecerating:(WLBannerView *)bannerView;
- (void) bannerView:(WLBannerView *)bannerView didClickItemAtIndex:(NSUInteger)index;
@end
/**由外部指定数据源类型，默认的只支持NSString或者UIImage类型
 * 自定义类型需要Cell继承WLBannerViewCell，自发实现数据源更新方法
 */
@interface WLBannerView<T> : UIScrollView
/**当前第几页
 */
@property (nonatomic, assign, readonly) NSInteger cur_index;
/**滚动代理
 */
@property (nonatomic, weak) id<WLBannerViewDelegate> bannerDelegate;
/**是否开启自动滚动
 */
@property (nonatomic, assign, getter=isAutoScrollEnabled) BOOL autoScroll;
/**自动滚动时间间隔
 */
@property (nonatomic, assign) float autoScrollInterval;

/**指定cell类名的构造函数，默认是 WLBannerViewCell
 */
- (instancetype) initWithCellCls:(Class)cls NS_DESIGNATED_INITIALIZER;
/**设置数据源，此数据源类型可自定义，默认数组中只包含UIImage或者NSString类型
 若需要自定义数据源，则对应的cell也需要继承自WLBannerViewCell自定义
 */
- (void) setupData:(NSArray<T> *)data;
/**刷新，布局cell
 */
- (void) reload;
/**手动设置显示到第几张
 */
- (void) scrollToIndex:(NSInteger)index;
@end

NS_ASSUME_NONNULL_END
