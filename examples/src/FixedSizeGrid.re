[@react.component]
let make = () => {
  <div>
    <div> {"Fixed Size Grid" |> React.string} </div>
    <ReactWindow.FixedSizeGrid
      className="classname-test-grid"
      columnCount=1000
      columnWidth=100
      height={Px(200)}
      rowCount=1000
      rowHeight=35
      innerElementType="div"
      width={Px(300)}>
      {({rowIndex, columnIndex, style}) =>
         <div style>
           {"Item"
            ++ string_of_int(rowIndex)
            ++ ","
            ++ string_of_int(columnIndex)
            |> React.string}
         </div>}
    </ReactWindow.FixedSizeGrid>
  </div>;
};