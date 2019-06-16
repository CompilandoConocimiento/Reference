import React, { FunctionComponent } from "react"

import { Drawer, Hidden } from "@material-ui/core"
import { useTheme } from "@material-ui/core/styles"

import ListOfTopics from "./ListOfTopics"
import useHeaderStyles from "./Styles"

import { isDrawerOpenDesktopContext } from "../App/Wrapper"

const DrawerSideMenu: FunctionComponent<{
  mobileOpen: boolean
  handleMobileDrawerToggle: () => void
}> = props => {
  const Styles = useHeaderStyles()
  const theme = useTheme()

  const [desktopOpen] = React.useContext(isDrawerOpenDesktopContext)

  const anchor = theme.direction === "rtl" ? "right" : "left"
  const classes = { paper: Styles.DrawerPaper }

  return (
    <nav className={Styles.Drawer}>
      <Hidden smUp implementation="css">
        <Drawer
          variant="temporary"
          anchor={anchor}
          classes={classes}
          open={props.mobileOpen}
          onClose={props.handleMobileDrawerToggle}
          ModalProps={{ keepMounted: true }}
        >
          <ListOfTopics />
        </Drawer>
      </Hidden>

      <Hidden xsDown implementation="css">
        <Drawer variant="persistent" anchor={anchor} classes={classes} open={desktopOpen}>
          <ListOfTopics />
        </Drawer>
      </Hidden>
    </nav>
  )
}

export default DrawerSideMenu
