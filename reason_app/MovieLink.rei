// type t;
// [@mel.module "@remix-run/react"] [@react.component]
// external make:
//   (
//     ~className: string,
//     ~to_: string,
//     ~prefetch: bool,
//     ~onMouseEnter: t,
//     ~onFocus: t,
//     ~children: React.element
//   ) =>
//   React.element =
//   "Link";

type movie;
[@react.component]
let default: (~movie: movie) => React.element;
