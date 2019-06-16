import React, { FunctionComponent, Dispatch, SetStateAction } from "react"
import { HashRouter } from "react-router-dom"

import { createMuiTheme, responsiveFontSizes } from "@material-ui/core/styles"
import { ThemeProvider } from "@material-ui/styles"
import TopicsData from "../../Data/TopicsData"

type correctType = [boolean, Dispatch<SetStateAction<boolean>>]
const warnUser = () => console.warn("Error: isDrawerOpenDesktopContext ")
const isDrawerOpenDesktopContext = React.createContext([false, warnUser] as correctType)

const myTheme = createMuiTheme({
  palette: {
    text: { primary: "#37474f" },
    primary: { main: "#37474f" },
    secondary: { main: "#f44336" },
  },
})

const IndexDataContext = React.createContext(TopicsData)

/**
 * This is a wrapper of all the app
 */
const Wrapper: FunctionComponent = ({ children }) => {
  const theme = responsiveFontSizes(myTheme)

  return (
    <React.StrictMode>
      <HashRouter>
        <ThemeProvider theme={theme}>
          <IndexDataContext.Provider value={TopicsData}>{children}</IndexDataContext.Provider>
        </ThemeProvider>
      </HashRouter>
    </React.StrictMode>
  )
}

export { IndexDataContext, isDrawerOpenDesktopContext }

export default Wrapper
