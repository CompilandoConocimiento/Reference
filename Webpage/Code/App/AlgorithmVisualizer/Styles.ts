import { makeStyles, createStyles, Theme } from "@material-ui/core/styles"

import { agate, hybrid, nord, solarizedLight } from "react-syntax-highlighter/dist/esm/styles/hljs"
import { atomOneDarkReasonable, obsidian } from "react-syntax-highlighter/dist/esm/styles/hljs"
import { tomorrowNightEighties, dracula } from "react-syntax-highlighter/dist/esm/styles/hljs"

const themes = [
  "agate",
  "atomOneDark",
  "hybrid",
  "dracula",
  "obsidian",
  "tomorrowNight",
  "solarizedLight",
  "nord",
]
const getCodeStyle = (styleName: string) => {
  switch (styleName) {
    case "agate":
      return agate
    case "atomOneDark":
      return atomOneDarkReasonable
    case "hybrid":
      return hybrid
    case "dracula":
      return dracula
    case "obsidian":
      return obsidian
    case "tomorrowNight":
      return tomorrowNightEighties
    case "solarizedLight":
      return solarizedLight
    case "nord":
      return nord
    default:
      return agate
  }
}

const useStyles = makeStyles((theme: Theme) =>
  createStyles({
    ArticleTitle: {
      textAlign: "center",
      marginBottom: "2.5rem",
      fontSize: "small",
    },
    ArticleBody: {
      [theme.breakpoints.up("sm")]: { fontSize: "inherit" },
      [theme.breakpoints.up("lg")]: { fontSize: "initial" },
    },
    FAB: {
      margin: 0,
      right: theme.spacing(2),
      bottom: theme.spacing(3),
      top: "auto",
      left: "auto",
      position: "fixed",
    },
  })
)

const baseCodeStyle = {
  padding: "1.2rem",
  marginTop: "1.5rem",
  marginBottom: "1.5rem",
  maxWidth: "100%",
  borderRadius: "0.8rem",
  boxShadow: "0 1px 3px rgba(0,0,0,0.12), 0 1px 2px rgba(0,0,0,0.24)",
}

export { baseCodeStyle, getCodeStyle, themes }
export default useStyles
