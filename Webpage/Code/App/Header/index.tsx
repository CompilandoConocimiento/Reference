import React, { Dispatch, SetStateAction } from "react"
import { Link } from "react-router-dom"

import { AppBar, Toolbar, Typography, IconButton } from "@material-ui/core"
import { Home, Menu } from "@material-ui/icons"

import clsx from "clsx"

import { DrawerSituationDesktopContext, ChangeDrawerSituationDesktopContext } from "../App/"
import useHeaderStyles from "./Styles"
import DrawerSideMenu from "./DrawerSideMenu"

type changeDrawer = [boolean, Dispatch<SetStateAction<boolean>>]
const DrawerSituationMobileContext = React.createContext<changeDrawer>([false, () => {}])

const Header = () => {
  const HeaderStyle = useHeaderStyles()
  const { AppBarShift, AppBarTitle, AppBarStyle } = HeaderStyle
  const { Hide, MenuButtonDesktop, MenuButtonMobile } = HeaderStyle

  const isDesktopDrawerOpen = React.useContext(DrawerSituationDesktopContext)
  const setDesktopOpen = React.useContext(ChangeDrawerSituationDesktopContext)

  const DrawerSituationMobile = React.useState(false)
  const [isMobileOpen, setMobileOpen] = DrawerSituationMobile

  const DesktopButtonStyle = clsx(MenuButtonDesktop, isDesktopDrawerOpen && Hide)
  const MobileButtonStyle = clsx(MenuButtonMobile, isMobileOpen && Hide)

  return (
    <React.Fragment>
      <AppBar position="fixed" className={clsx(AppBarStyle, isDesktopDrawerOpen && AppBarShift)}>
        <Toolbar>
          <DrawerIcon onClick={() => setDesktopOpen(val => !val)} className={DesktopButtonStyle} />
          <DrawerIcon onClick={() => setMobileOpen(val => !val)} className={MobileButtonStyle} />

          <Typography variant="h5" noWrap className={AppBarTitle}>
            <span style={{ fontWeight: 500 }}>Competitive</span>{" "}
            <span style={{ fontWeight: 300 }}>Reference</span>
          </Typography>

          <IconButton color="inherit" component={Link} to={""}>
            <Home />
          </IconButton>
        </Toolbar>
      </AppBar>

      <DrawerSituationMobileContext.Provider value={DrawerSituationMobile}>
        <DrawerSideMenu />
      </DrawerSituationMobileContext.Provider>
    </React.Fragment>
  )
}

function DrawerIcon({ onClick, className }) {
  return (
    <IconButton edge="start" color="inherit" aria-label="Open Drawer" {...{ onClick, className }}>
      <Menu />
    </IconButton>
  )
}

export { DrawerSituationMobileContext }
export default Header
