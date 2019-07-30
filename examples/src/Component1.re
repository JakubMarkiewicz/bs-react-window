let getItemSize = index => index mod 2 === 0 ? 50 : 25;

[@react.component]
let make = () => {
  <div>
    <div> {"Fixed Size List" |> React.string} </div>
    <ReactWindow.FixedSizeList
      className="classname-test"
      direction=`rtl
      useIsScrolling=true
      height={Px(200)}
      initialScrollOffset=500
      innerElementType="div"
      itemCount=1000
      itemSize=35
      width={Px(300)}>
      {({index, style, isScrolling}) =>
         <div style>
           {switch (isScrolling) {
            | true => "Scrolling" |> React.string
            | _ => index |> string_of_int |> React.string
            }}
         </div>}
    </ReactWindow.FixedSizeList>
  </div>;
};