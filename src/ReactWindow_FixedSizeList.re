open Utils;

/* TODO:
     itemKey
     onItemsRender
     onScroll
   */

module Internal = {
  [@bs.module "react-window"] [@react.component]
  external make:
    (
      ~children: List.renderPropObjJS => React.element,
      ~className: string=?,
      ~direction: string=?,
      ~height: 'a,
      ~initialScrollOffset: int=?,
      ~innerRef: React.Ref.t('b)=?,
      ~innerElementType: string=?,
      ~itemCount: int,
      ~itemData: array('data)=?,
      ~itemKey: (int, 'c) => string=?,
      ~itemSize: int,
      ~layout: string=?,
      ~outerRef: React.Ref.t('d)=?,
      ~outerElementType: string=?,
      ~overscanCount: int=?,
      ~style: ReactDOMRe.Style.t=?,
      ~useIsScrolling: bool=?,
      ~width: 'a
    ) =>
    React.element =
    "FixedSizeList";
};

[@react.component]
let make =
    (
      ~children: List.renderProp => React.element,
      ~className: string=?,
      ~direction: option(direction)=?,
      ~height: size('a),
      ~initialScrollOffset: int=?,
      ~innerRef: React.Ref.t('b)=?,
      ~innerElementType: string=?,
      ~itemCount: int=?,
      ~itemData: array('data)=?,
      ~itemKey: (int, array('data)) => string=?,
      ~itemSize: int,
      ~layout: option(layout)=?,
      ~outerRef: React.Ref.t('d)=?,
      ~outerElementType: string=?,
      ~overscanCount: int=?,
      ~style: ReactDOMRe.Style.t=?,
      ~useIsScrolling: bool=?,
      ~width: size('a),
    ) =>
  <Internal
    className
    direction=?{Belt.Option.map(direction, directionToJs)}
    height={sizeToString(height)}
    initialScrollOffset
    innerRef
    innerElementType
    itemCount
    itemData
    itemKey
    itemSize
    layout=?{Belt.Option.map(layout, layoutToJs)}
    outerRef
    outerElementType
    overscanCount
    style
    useIsScrolling
    width={sizeToString(width)}>
    {renderProps => renderProps |> List.convertJsInputToReason |> children}
  </Internal>;