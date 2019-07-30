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
      ~children: Grid.renderPropObjJS => React.element,
      ~className: string=?,
      ~columnCount: int,
      ~columnWidth: int,
      ~direction: string=?,
      ~height: 'a,
      ~initialScrollLeft: int=?,
      ~initialScrollTop: int=?,
      ~innerRef: React.Ref.t('b)=?,
      ~innerElementType: string=?,
      ~itemData: array('data)=?,
      ~layout: string=?,
      ~outerRef: React.Ref.t('d)=?,
      ~outerElementType: string=?,
      ~overscanColumnCount: int=?,
      ~overscanRowCount: int=?,
      ~rowCount: int,
      ~rowHeight: int,
      ~style: ReactDOMRe.Style.t=?,
      ~useIsScrolling: bool=?,
      ~width: 'a
    ) =>
    React.element =
    "FixedSizeGrid";
};

[@react.component]
let make =
    (
      ~children: Grid.renderProp => React.element,
      ~className: string=?,
      ~columnCount: int,
      ~columnWidth: int,
      ~direction: option(direction)=?,
      ~height: size('a),
      ~initialScrollLeft: int=?,
      ~initialScrollTop: int=?,
      ~innerRef: React.Ref.t('b)=?,
      ~innerElementType: string=?,
      ~itemData: array('data)=?,
      ~layout: option(layout)=?,
      ~outerRef: React.Ref.t('d)=?,
      ~outerElementType: string=?,
      ~overscanColumnCount: int=?,
      ~overscanRowCount: int=?,
      ~rowCount: int,
      ~rowHeight: int,
      ~style: ReactDOMRe.Style.t=?,
      ~useIsScrolling: bool=?,
      ~width: size('a),
    ) =>
  <Internal
    className
    columnCount
    columnWidth
    direction=?{Belt.Option.map(direction, directionToJs)}
    height={sizeToString(height)}
    initialScrollLeft
    initialScrollTop
    innerRef
    innerElementType
    itemData
    layout=?{Belt.Option.map(layout, layoutToJs)}
    outerRef
    outerElementType
    overscanColumnCount
    overscanRowCount
    rowCount
    rowHeight
    style
    useIsScrolling
    width={sizeToString(width)}>
    {renderProps => renderProps |> Grid.convertJsInputToReason |> children}
  </Internal>;