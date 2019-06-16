import React from "react"
import { Link } from "react-router-dom"

import { AppBar, Toolbar, IconButton, Typography } from "@material-ui/core"
import { Home, Menu } from "@material-ui/icons"

import clsx from "clsx"

import { DrawerSituationDesktopContext, ChangeDrawerSituationDesktopContext } from "../App/"
import useHeaderStyles from "./Styles"
import DrawerSideMenu from "./DrawerSideMenu"

const DrawerIcon = ({ onClick, className }) => (
  <IconButton
    edge="start"
    color="inherit"
    aria-label="Open drawer"
    onClick={onClick}
    className={className}
  >
    <Menu />
  </IconButton>
)

const Header = () => {
  const Styles = useHeaderStyles()

  const isDrawerOpen = React.useContext(DrawerSituationDesktopContext)
  const setDesktopOpen = React.useContext(ChangeDrawerSituationDesktopContext)
  const [mobileOpen, setMobileOpen] = React.useState(false)

  const desktopDrawerToggle = () => setDesktopOpen(!isDrawerOpen)
  const mobileDrawerToggle = () => setMobileOpen(!mobileOpen)
  const closeMobileDrawer = () => setMobileOpen(false)

  const AppBarStyle = clsx(Styles.AppBar, isDrawerOpen && Styles.AppBarShift)
  const toggleDesktopButtonStyle = clsx(Styles.MenuButtonDesktop, isDrawerOpen && Styles.Hide)
  const toggleMobileButtonStyle = clsx(Styles.MenuButtonMobile, mobileOpen && Styles.Hide)

  return (
    <React.Fragment>
      <AppBar position="fixed" className={AppBarStyle}>
        <Toolbar>
          <DrawerIcon onClick={desktopDrawerToggle} className={toggleDesktopButtonStyle} />
          <DrawerIcon onClick={mobileDrawerToggle} className={toggleMobileButtonStyle} />
          <Typography variant="h5" noWrap className={Styles.AppBarTitle}>
            <span style={{ fontWeight: 500 }}>Competitive</span>{" "}
            <span style={{ fontWeight: 300 }}>Reference</span>
          </Typography>
          <IconButton color="inherit" component={Link} to={""}>
            <Home />
          </IconButton>
        </Toolbar>
      </AppBar>

      <DrawerSideMenu mobileOpen={mobileOpen} closeMobileDrawer={closeMobileDrawer} />
    </React.Fragment>
  )
}

export default Header
