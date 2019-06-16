import React, { FunctionComponent, useContext } from "react"

import { Drawer, Hidden } from "@material-ui/core"
import { useTheme } from "@material-ui/core/styles"

import ListOfTopics from "./ListOfTopics"
import useHeaderStyles from "./Styles"

import { DrawerSituationDesktopContext } from "../App/"
import { DrawerSituationMobileContext } from "../Header"

const DrawerSideMenu: FunctionComponent = () => {
  const Styles = useHeaderStyles()
  const theme = useTheme()

  const [isMobileOpen, setMobileOpen] = useContext(DrawerSituationMobileContext)
  const isDesktopOpen = useContext(DrawerSituationDesktopContext)

  const anchor = (theme.direction === "rtl" ? "right" : "left") as "right" | "left"
  const DesktopProps = { anchor, classes: { paper: Styles.DrawerPaper }, open: isDesktopOpen }
  const MobileProps = { ...DesktopProps, open: isMobileOpen, ModalProps: { keepMounted: true } }

  return (
    <nav className={Styles.Drawer}>
      <Hidden smUp implementation="css">
        <Drawer variant="temporary" {...MobileProps} onClose={() => setMobileOpen(false)}>
          <ListOfTopics />
        </Drawer>
      </Hidden>

      <Hidden xsDown implementation="css">
        <Drawer variant="persistent" {...DesktopProps}>
          <ListOfTopics />
        </Drawer>
      </Hidden>
    </nav>
  )
}

export default DrawerSideMenu
