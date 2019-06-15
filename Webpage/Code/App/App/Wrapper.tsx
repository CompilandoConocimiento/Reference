import React, { FunctionComponent } from "react"
import { HashRouter } from "react-router-dom"

import { createMuiTheme } from "@material-ui/core/styles"
import { ThemeProvider } from "@material-ui/styles"
import TopicsData from "../../Data/TopicsData"


const theme = createMuiTheme({
  palette: {
    primary: { main: "#37474f" },
    secondary: { main: "#f44336" },
  },
})

const IndexDataContext = React.createContext(TopicsData)

/**
 * This is a wrapper of all the app
 */
const Wrapper: FunctionComponent = ({ children }) => {
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

export { IndexDataContext }

export default Wrapper
