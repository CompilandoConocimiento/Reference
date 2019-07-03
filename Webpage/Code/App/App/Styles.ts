import { makeStyles, Theme as ThemeType, createStyles } from "@material-ui/core/styles"
import { createMuiTheme, responsiveFontSizes } from "@material-ui/core/styles"

import { red, blueGrey, indigo, cyan, green, brown, deepPurple } from "@material-ui/core/colors/"
import { fontSize } from "@material-ui/system";

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

const useMainStyles = makeStyles((theme: ThemeType) => {
  return createStyles({
    Footer: {
      marginTop: 'auto',
      color: "white",
      fontWeight: 500
    },
    FooterEnd: {
      padding: theme.spacing(2),
      backgroundColor: blueGrey[900],
    },
    FooterUL: {
      marginTop: 0,
      paddingLeft: "1rem",
      fontWeight: 600,
      fontSize: "0.9rem"
    },
    Links: {
      color: "white",
    },
    FooterMain: {
      padding: theme.spacing(2),
      backgroundColor: blueGrey[700],
    },
  })
})

export { Theme, Colors, useMainStyles }
