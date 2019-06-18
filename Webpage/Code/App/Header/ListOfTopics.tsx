import React, { FunctionComponent, useContext, useReducer } from "react"
import { Link } from "react-router-dom"

import { Collapse, List, ListItem, ListItemText, IconButton } from "@material-ui/core"
import { ChevronLeft, ChevronRight, ExpandLess, ExpandMore } from "@material-ui/icons"
import { useTheme } from "@material-ui/core/styles"

import { DataContext, ChangeDrawerSituationDesktopContext } from "../App"
import { DrawerSituationMobileContext } from "../Header"
import useHeaderStyles from "./Styles"

const ListTopics: FunctionComponent = () => {
  const theme = useTheme()
  const Styles = useHeaderStyles()
  const Data = useContext(DataContext)

  const setDesktopOpen = useContext(ChangeDrawerSituationDesktopContext)
  const toggleMobile = useContext(DrawerSituationMobileContext)[1]
  const [TopicsClosed, toggleOpenTopics] = useReducer((oldState: Array<boolean>, id: number) => {
    const newState = [...oldState]
    newState[id] = !newState[id]
    return newState
  }, [])

  const TopicTitleProps = { variant: "h5" as "h5", className: Styles.DrawerTitle }
  const TopicSubTitleProps = { variant: "subtitle2" as "subtitle2", className: Styles.DrawerTopic }
  const AlgoProps = { variant: "subtitle2" as "subtitle2", className: Styles.DrawerAlgorithm }
  const toggleDesktopDrawer = () => setDesktopOpen(val => !val)

  return (
    <React.Fragment>
      <List>
        <ListItem alignItems={"flex-start"}>
          <ListItemText primary={"Topics"} primaryTypographyProps={TopicTitleProps} />
          <IconButton edge="end" className={Styles.MenuButtonDesktop} onClick={toggleDesktopDrawer}>
            {theme.direction === "ltr" ? <ChevronLeft /> : <ChevronRight />}
          </IconButton>
        </ListItem>

        {Data.map((Topic, id) => {
          const baseLink = `/Topic/${Topic.link}/`
          const onClick = () => toggleMobile(false)

          return (
            <React.Fragment key={Topic.name}>
              <ListItem button alignItems="center" onClick={onClick} component={Link} to={baseLink}>
                <ListItemText primary={Topic.name} primaryTypographyProps={TopicSubTitleProps} />
                <IconButton edge="end" onClick={e => [e.stopPropagation(), toggleOpenTopics(id)]}>
                  {TopicsClosed[id] ? <ExpandMore /> : <ExpandLess />}
                </IconButton>
              </ListItem>

              <Collapse in={!TopicsClosed[id]} timeout="auto" unmountOnExit>
                <List disablePadding>
                  {Topic.Algorithms.map(({ link, name }) => {
                    const props = { onClick, alignItems: "flex-start" as "flex-start" }
                    return (
                      <ListItem button key={name} component={Link} to={baseLink + link} {...props}>
                        <ListItemText primaryTypographyProps={AlgoProps} primary={name} />
                      </ListItem>
                    )
                  })}
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
