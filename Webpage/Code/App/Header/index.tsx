import React from "react"
import { Link } from "react-router-dom"

import { AppBar, Toolbar, IconButton, Typography } from "@material-ui/core"
import { Home, Menu } from "@material-ui/icons"
import clsx from "clsx"

import { isDrawerOpenDesktopContext } from "../App/Wrapper"
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

  const [desktopOpen, setDesktopOpen] = React.useContext(isDrawerOpenDesktopContext)
  const [mobileOpen, setMobileOpen] = React.useState(false)

  const handleDesktopDrawerToggle = () => setDesktopOpen(!desktopOpen)
  const handleMobileDrawerToggle = () => setMobileOpen(!mobileOpen)

  const AppBarStyle = clsx(Styles.AppBar, desktopOpen && Styles.AppBarShift)
  const toggleDesktopButtonStyle = clsx(Styles.MenuButtonDesktop, desktopOpen && Styles.hide)
  const toggleMobileButtonStyle = clsx(Styles.MenuButtonMobile, mobileOpen && Styles.hide)

  return (
    <React.Fragment>
      <AppBar position="fixed" className={AppBarStyle}>
        <Toolbar>
          <DrawerIcon onClick={handleDesktopDrawerToggle} className={toggleDesktopButtonStyle} />
          <DrawerIcon onClick={handleMobileDrawerToggle} className={toggleMobileButtonStyle} />
          <Typography variant="h6" noWrap className={Styles.AppBarTitle}>
            Compilando Conocimiento
          </Typography>
          <IconButton color="inherit" component={Link} to={""}>
            <Home />
          </IconButton>
        </Toolbar>
      </AppBar>

      <DrawerSideMenu mobileOpen={mobileOpen} handleMobileDrawerToggle={handleMobileDrawerToggle} />
    </React.Fragment>
  )
}

export default Header
