import ReactDOM from "react-dom"
import React, { FunctionComponent, useContext } from "react"
import { Switch, Route } from "react-router-dom"

import clsx from "clsx"

import Header from "../Header"
import Home from "../Home"
import AlgorithmsPicker from "../AlgorithmsPicker"

import Wrapper, { DataContext } from "./Wrapper"
import { DrawerSituationDesktopContext, ChangeDrawerSituationDesktopContext } from "./Wrapper"
import { ErrorMessage } from "../Helpers"

import useHeaderStyles from "../Header/Styles"

/**
 * This is a wrapper of all the app, the header, the footer and
 * the content. It also moves the content if we have the drawer open
 */
const App: FunctionComponent = () => {
  const TopicsData = useContext(DataContext)
  const isDesktopDrawerOpen = useContext(DrawerSituationDesktopContext)

  const Styles = useHeaderStyles()
  const ContentMargin = clsx(Styles.Content, { [Styles.ContentShift]: isDesktopDrawerOpen })

  return (
    <React.Fragment>
      <Header />
      <main className={ContentMargin}>
        <div className={Styles.SpaceForTheHeader} />
        <Switch>
          <Route exact path="/" component={Home} />
          <Route
            path="/Topic/:topicLink"
            render={props => {
              const topicLink = props.match.params.topicLink
              const topic = TopicsData.find(Topic => Topic.link === topicLink)
              if (!topic) return <ErrorMessage />

              return <AlgorithmsPicker TopicData={topic} />
            }}
          />
          <Route path="/:SomethingElse" component={Home} />
        </Switch>
      </main>
    </React.Fragment>
  )
}

const DOMNode = document.getElementById("ReactApp")
ReactDOM.render(
  <Wrapper>
    <App />
  </Wrapper>,
  DOMNode
)

export { DataContext, DrawerSituationDesktopContext, ChangeDrawerSituationDesktopContext }
