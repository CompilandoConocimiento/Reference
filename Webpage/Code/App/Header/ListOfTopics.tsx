import React, { FunctionComponent, useContext, useReducer } from "react"
import { Link } from "react-router-dom"

import { ChevronLeft, ChevronRight, ExpandLess, ExpandMore } from "@material-ui/icons"
import { Collapse, List, ListItem, ListItemText, IconButton } from "@material-ui/core"
import { useTheme } from "@material-ui/core/styles"

import { IndexDataContext, isDrawerOpenDesktopContext } from "../App"
import useHeaderStyles from "./Styles"

const ListTopics: FunctionComponent = () => {
  const IndexData = useContext(IndexDataContext)
  const theme = useTheme()
  const Styles = useHeaderStyles()

  const [desktopOpen, setDesktopOpen] = React.useContext(isDrawerOpenDesktopContext)
  const handleDesktopDrawerToggle = () => setDesktopOpen(!desktopOpen)

  const [TopicsOpened, toggleOpen] = useReducer((oldState: Array<boolean>, id: number) => {
    const newState = [...oldState]
    newState[id] = !newState[id]

    return newState
  }, [])

  return (
    <React.Fragment>
      <List>
        <ListItem alignItems={"flex-start"}>
          <ListItemText
            primary={"Topics"}
            primaryTypographyProps={{ variant: "h5", className: Styles.DrawerTitle }}
          />
          <IconButton
            edge="end"
            className={Styles.MenuButtonDesktop}
            onClick={handleDesktopDrawerToggle}
          >
            {theme.direction === "ltr" ? <ChevronLeft /> : <ChevronRight />}
          </IconButton>
        </ListItem>

        {IndexData.map((Topic, id) => {
          const baseLink = `/Topic/${Topic.link}/`

          return (
            <React.Fragment key={Topic.name}>
              <ListItem alignItems="center" button component={Link} to={baseLink}>
                <ListItemText
                  primary={Topic.name}
                  primaryTypographyProps={{ variant: "subtitle2", className: Styles.DrawerTopic }}
                />
                <IconButton
                  edge="end"
                  onClick={e => {
                    toggleOpen(id)
                    e.preventDefault()
                  }}
                >
                  {TopicsOpened[id] ? <ExpandLess /> : <ExpandMore />}
                </IconButton>
              </ListItem>

              <Collapse in={TopicsOpened[id]} timeout="auto" unmountOnExit>
                <List disablePadding>
                  {Topic.Algorithms.map(algorithm => (
                    <ListItem
                      button
                      key={algorithm.name}
                      alignItems={"flex-start"}
                      component={Link}
                      to={baseLink + algorithm.link}
                    >
                      <ListItemText
                        primaryTypographyProps={{
                          variant: "subtitle2",
                          className: Styles.DrawerAlgorithm,
                        }}
                        primary={algorithm.name}
                      />
                    </ListItem>
                  ))}
                </List>
              </Collapse>
            </React.Fragment>
          )
        })}
      </List>
    </React.Fragment>
  )
}

export default ListTopics
