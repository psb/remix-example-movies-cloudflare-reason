module Link = {
  [@mel.module "@remix-run/react"] [@react.component]
  // ~className: string,
  external make:
    (
      ~_to: string,
      ~prefetch: string,
      ~onMouseEnter: unit => unit,
      ~onFocus: unit => unit,
      ~children: React.element
    ) =>
    React.element =
    "Link";
};

type movie = {
  id: string,
  thumbnail: string,
  title: string,
};

type sessionStorage;
external sessionStorage: sessionStorage = "sessionStorage";

[@mel.send] [@mel.return nullable]
external getItem: (sessionStorage, string) => option(movie) = "getItem";

type image;
[@mel.new] external create_image: unit => image = "Image";
[@mel.set] external set_src: (image, string) => unit = "src";

[@react.component]
let default = (~movie: movie) => {
  let (prefetch, setPrefetch) = React.useState(() => "intent");

  let movieId = movie.id;

  React.useEffect0(() => {
    let item = getItem(sessionStorage, {j|movie-$movieId|j});

    switch (item) {
    | Some(_) => setPrefetch(_ => "none")
    | None => ()
    };

    Some(() => ()); // required for Some Reason (puns intended)
  });

  let prefetchImage = () =>
    if (prefetch != "none") {
      let image = create_image();
      set_src(image, movie.thumbnail);
    };

  <Link
    _to={j|/movie/$movieId|j}
    prefetch
    onMouseEnter=prefetchImage
    onFocus=prefetchImage>
    {React.string(movie.title)}
  </Link>;
};
