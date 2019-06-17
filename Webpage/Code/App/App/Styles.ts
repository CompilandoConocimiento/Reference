import { createMuiTheme, responsiveFontSizes } from "@material-ui/core/styles"

import { red, indigo, cyan, green, brown, deepPurple } from "@material-ui/core/colors/"

const Colors = [red[600], indigo[700], deepPurple[800], cyan[800], green[600], brown[600]].sort(
  () => Math.random() - 0.5
)



const Theme = responsiveFontSizes(
  createMuiTheme({
    palette: {
      primary: { main: "#37474f" },
      secondary: { main: "#f44336" },
    },
    typography: {
      fontFamily: [
        "-apple-system",
        "BlinkMacSystemFont",
        '"Segoe UI"',
        "Roboto",
        "firacode",
        '"Helvetica Neue"',
        "Arial",
        "sans-serif",
        '"Apple Color Emoji"',
        '"Segoe UI Emoji"',
        '"Segoe UI Symbol"',
      ].join(","),
    },
  })
)

export { Theme, Colors }
