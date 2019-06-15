import React, { Dispatch, SetStateAction } from "react"

import { Drawer, Hidden } from "@material-ui/core"

import IconButton from "@material-ui/core/IconButton"


import List from "@material-ui/core/List"
import Divider from "@material-ui/core/Divider"
import { useTheme } from "@material-ui/core/styles"

import ChevronLeftIcon from "@material-ui/icons/ChevronLeft"
import ChevronRightIcon from "@material-ui/icons/ChevronRight"

import ListItem from "@material-ui/core/ListItem"

import ListItemIcon from "@material-ui/core/ListItemIcon"
import ListItemText from "@material-ui/core/ListItemText"

import InboxIcon from "@material-ui/icons/MoveToInbox"
import MailIcon from "@material-ui/icons/Mail"
import useHeaderStyles from "./Styles"

import { isDrawerOpenDesktopContext } from "../App/Wrapper"

interface DrawerSideMenuProps {
  mobileOpen: boolean
  handleMobileDrawerToggle: Dispatch<SetStateAction<boolean>>
}
const DrawerSideMenu = (props: DrawerSideMenuProps) => {
  const Styles = useHeaderStyles()
  const theme = useTheme()

  const [desktopOpen, setDesktopOpen] = React.useContext(isDrawerOpenDesktopContext)
  const handleDesktopDrawerToggle = () => setDesktopOpen(!desktopOpen)

  return (
    <nav className={Styles.drawer}>
      <Hidden smUp implementation="css">
        <Drawer
          variant="temporary"
          anchor={theme.direction === "rtl" ? "right" : "left"}
          open={props.mobileOpen}
          onClose={props.handleMobileDrawerToggle}
          classes={{
            paper: Styles.drawerPaper,
          }}
          ModalProps={{
            keepMounted: true, // Better open performance on mobile.
          }}
        >
          Hola
        </Drawer>
      </Hidden>

      <Hidden xsDown implementation="css">
        <Drawer
          variant="persistent"
          anchor="left"
          open={desktopOpen}
          classes={{
            paper: Styles.drawerPaper,
          }}
        >
          <div className={Styles.DrawerHeader}>
            <IconButton onClick={handleDesktopDrawerToggle}>
              {theme.direction === "ltr" ? <ChevronLeftIcon /> : <ChevronRightIcon />}
            </IconButton>
          </div>
          <Divider />
          <List>
            {["Inbox", "Starred", "Send email", "Drafts"].map((text, index) => (
              <ListItem button key={text}>
                <ListItemIcon>{index % 2 === 0 ? <InboxIcon /> : <MailIcon />}</ListItemIcon>
                <ListItemText primary={text} />
              </ListItem>
            ))}
          </List>
          <Divider />
          <List>
            {["All mail", "Trash", "Spam"].map((text, index) => (
              <ListItem button key={text}>
                <ListItemIcon>{index % 2 === 0 ? <InboxIcon /> : <MailIcon />}</ListItemIcon>
                <ListItemText primary={text} />
              </ListItem>
            ))}
          </List>
        </Drawer>
      </Hidden>
    </nav>
  )
}

export default DrawerSideMenu