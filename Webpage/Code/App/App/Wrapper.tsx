import React, { FunctionComponent, useState, Dispatch, SetStateAction } from "react"
import { HashRouter } from "react-router-dom"

import { ThemeProvider } from "@material-ui/styles"
import { CssBaseline } from "@material-ui/core"

import Data from "../../Data/TopicsData"
import useHeaderStyles from "../Header/Styles"
import { Theme } from "./Styles"

type changeDrawer = Dispatch<SetStateAction<boolean>>
const ChangeDrawerSituationDesktopContext = React.createContext<changeDrawer>(() => {})
const DrawerSituationDesktopContext = React.createContext(false)
const DataContext = React.createContext(Data)

/**
 * This is a wrapper of all the app, all the contexts,
 * MaterialUI CSS, Router, and Strict Mode
 */
const Wrapper: FunctionComponent = ({ children }) => {
  const [isOpen, setSituation] = useState(false)
  const Styles = useHeaderStyles()

  return (
    <React.StrictMode>
      <HashRouter>
        <ThemeProvider theme={Theme}>
          <DataContext.Provider value={Data}>
            <DrawerSituationDesktopContext.Provider value={isOpen}>
              <ChangeDrawerSituationDesktopContext.Provider value={setSituation}>
                <div className={Styles.Root}>
                  <CssBaseline />
                  {children}
                </div>
              </ChangeDrawerSituationDesktopContext.Provider>
            </DrawerSituationDesktopContext.Provider>
          </DataContext.Provider>
        </ThemeProvider>
      </HashRouter>
    </React.StrictMode>
  )
}

export { DataContext, DrawerSituationDesktopContext, ChangeDrawerSituationDesktopContext }
export default Wrapper
