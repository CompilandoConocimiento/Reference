import React, { Dispatch, SetStateAction } from "react"

import { Drawer, Hidden, Divider, IconButton } from "@material-ui/core"
import { List, ListItem, ListItemIcon, ListItemText } from "@material-ui/core"
import { useTheme } from "@material-ui/core/styles"
import { Typography, Box } from "@material-ui/core"

import { ChevronLeft, ChevronRight } from "@material-ui/icons"

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

  const theList = (
    <React.Fragment>
      <List>
        <Typography variant="h5" className={Styles.DrawerTitle}>
          <Box fontWeight={"fontWeightBold"}>Topics</Box>
        </Typography>
      </List>
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
    </React.Fragment>
  )

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
          {theList}
        </Drawer>
      </Hidden>

      <Hidden xsDown implementation="css">
        <Drawer variant="persistent" anchor={anchor} classes={classes} open={desktopOpen}>
          <div className={Styles.DrawerHeader}>
            <IconButton onClick={handleDesktopDrawerToggle}>
              {theme.direction === "ltr" ? <ChevronLeft /> : <ChevronRight />}
            </IconButton>
          </div>
          <Divider />
          {theList}
        </Drawer>
      </Hidden>
    </nav>
  )
}

export default DrawerSideMenu
