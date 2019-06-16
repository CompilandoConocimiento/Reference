import React, { useContext, FunctionComponent } from "react"
import { IndexDataContext } from "../App"

import { ChevronLeft, ChevronRight } from "@material-ui/icons"

import { List, ListItem, ListItemText, IconButton } from "@material-ui/core"
import { Link } from "react-router-dom"
import { ExpandLess, ExpandMore } from "@material-ui/icons"

import { useTheme } from "@material-ui/core/styles"
import useHeaderStyles from "./Styles"
import { isDrawerOpenDesktopContext } from "../App/Wrapper"

const ListTopics: FunctionComponent = () => {
  const IndexData = useContext(IndexDataContext)
  const theme = useTheme()
  const Styles = useHeaderStyles()

  const [desktopOpen, setDesktopOpen] = React.useContext(isDrawerOpenDesktopContext)
  const handleDesktopDrawerToggle = () => setDesktopOpen(!desktopOpen)

  return (
    <React.Fragment>
      <List>
        <ListItem alignItems={"flex-start"}>
          <ListItemText
            primaryTypographyProps={{ variant: "h5", className: Styles.DrawerTitle }}
            primary={"Topics"}
          />
          <IconButton
            className={Styles.MenuButtonDesktop}
            edge={"end"}
            onClick={handleDesktopDrawerToggle}
          >
            {theme.direction === "ltr" ? <ChevronLeft /> : <ChevronRight />}
          </IconButton>
        </ListItem>

        {IndexData.map(Topic => {
          const baseLink = `/Topic/${Topic.link}/`
          return (
            <React.Fragment key={Topic.name}>
              <ListItem alignItems={"flex-start"} button component={Link} to={baseLink}>
                <ListItemText
                  primaryTypographyProps={{ variant: "subtitle2" }}
                  primary={Topic.name}
                />
                {open != null ? open ? <ExpandLess /> : <ExpandMore /> : null}
              </ListItem>

              {Topic.Algorithms.map(algorithm => (
                <ListItem
                  key={algorithm.name}
                  alignItems={"flex-start"}
                  button
                  component={Link}
                  to={baseLink + algorithm.link}
                >
                  <ListItemText
                    primaryTypographyProps={{ variant: "subtitle2" }}
                    primary={algorithm.name}
                  />
                  {open != null ? open ? <ExpandLess /> : <ExpandMore /> : null}
                </ListItem>
              ))}
            </React.Fragment>
          )
        })}
      </List>
    </React.Fragment>
  )
}

export default ListTopics
