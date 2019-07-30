module Grid = {
  [@bs.deriving abstract]
  type renderPropObjJS = {
    index: int,
    style: ReactDOMRe.Style.t,
    isScrolling: bool,
    columnIndex: int,
    rowIndex: int,
  };

  type renderProp = {
    index: int,
    style: ReactDOMRe.Style.t,
    isScrolling: bool,
    columnIndex: int,
    rowIndex: int,
  };

  let convertJsInputToReason = (data: renderPropObjJS): renderProp => {
    index: data->indexGet,
    style: data->styleGet,
    isScrolling: data->isScrollingGet,
    columnIndex: data->columnIndexGet,
    rowIndex: data->rowIndexGet,
  };

  module ItemKey = {
    [@bs.deriving abstract]
    type itemKeyPropObjJS = {
      columnIndex: int,
      rowIndex: int,
    };
    type itemKeyProp = {
      columnIndex: int,
      rowIndex: int,
    };
    let convertJsInputToReason = (data: itemKeyPropObjJS): itemKeyProp => {
      columnIndex: data->columnIndexGet,
      rowIndex: data->rowIndexGet,
    };
  };
};

module List = {
  [@bs.deriving abstract]
  type renderPropObjJS = {
    index: int,
    style: ReactDOMRe.Style.t,
    isScrolling: bool,
  };

  type renderProp = {
    index: int,
    style: ReactDOMRe.Style.t,
    isScrolling: bool,
  };
  let convertJsInputToReason = (data: renderPropObjJS): renderProp => {
    index: data->indexGet,
    style: data->styleGet,
    isScrolling: data->isScrollingGet,
  };
};

type size(_) =
  | Px(int): size(int)
  | String(string): size(string);

let sizeToString = (type a, size: size(a)): a =>
  switch (size) {
  | Px(v) => v
  | String(v) => v
  };

[@bs.deriving jsConverter]
type layout = [ | `vertical | `horizontal];

[@bs.deriving jsConverter]
type direction = [ | `ltr | `rtl];