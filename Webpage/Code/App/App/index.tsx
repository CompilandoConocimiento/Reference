import React, { FunctionComponent, useContext, useCallback, useState } from "react"
import ReactDOM from "react-dom"
import { Switch, Route, RouteComponentProps } from "react-router-dom"

import CssBaseline from "@material-ui/core/CssBaseline"
import clsx from "clsx"

import Header from "../Header"
import Home from "../Home"
import AlgorithmsPicker from "../AlgorithmsPicker"
import { ErrorMessage } from "../Helpers"

import Wrapper, { IndexDataContext, isDrawerOpenDesktopContext } from "./Wrapper"
import useStyles from "../Header/Styles"

/**
 * This is a wrapper of all the app, the header, the footer and
 * the content.
 */
const App: FunctionComponent = () => {
  const TopicsData = useContext(IndexDataContext)
  const drawerSituation = useState(true)
  const [isDrawerOpen] = drawerSituation
  const classes = useStyles()

  const renderAlgorithmPicker = useCallback(
    (props: RouteComponentProps<{ topicLink: string }>) => {
      const topicLink = props.match.params.topicLink
      const topic = TopicsData.find(Topic => Topic.link === topicLink)

      if (!topic) return <ErrorMessage />

      return <AlgorithmsPicker TopicData={topic} />
    },
    [TopicsData]
  )

  return (
    <div className={classes.root}>
      <CssBaseline />
      <isDrawerOpenDesktopContext.Provider value={drawerSituation}>
        <Header />

        <main
          className={clsx(classes.content, {
            [classes.contentShift]: isDrawerOpen,
          })}
        >
          <div className={classes.drawerHeader} />
          <Switch>
            <Route exact path="/" component={Home} />
            <Route path="/Topic/:topicLink" render={renderAlgorithmPicker} />
            <Route path="/:SomethingElse" component={Home} />
          </Switch>
        </main>
      </isDrawerOpenDesktopContext.Provider>
    </div>
  )
}

export { IndexDataContext }

ReactDOM.render(
  <Wrapper>
    <App />
  </Wrapper>,
  document.getElementById("ReactApp")
)
