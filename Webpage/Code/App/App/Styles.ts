import { createMuiTheme, responsiveFontSizes } from "@material-ui/core/styles"

const myTheme = createMuiTheme({
  palette: {
    text: { primary: "#37474f" },
    primary: { main: "#37474f" },
    secondary: { main: "#f44336" },
  },
})

const Theme = responsiveFontSizes(myTheme)


export default Theme