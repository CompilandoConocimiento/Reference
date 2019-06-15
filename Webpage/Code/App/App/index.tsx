import React, { FunctionComponent, useContext, useCallback } from "react"
import ReactDOM from "react-dom"
import { Switch, Route, RouteComponentProps } from "react-router-dom"

import CssBaseline from "@material-ui/core/CssBaseline"
import clsx from "clsx"

import Header from "../Header"
import Footer from "../Footer"
import Home from "../Home"
import AlgorithmsPicker from "../AlgorithmsPicker"
import { ErrorMessage } from "../Helpers"

import Wrapper, { IndexDataContext } from "./Wrapper"
import useStyles from "../Header/Styles"

/**
 * This is a wrapper of all the app, the header, the footer and
 * the content.
 */
const App: FunctionComponent = () => {
  const TopicsData = useContext(IndexDataContext)
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

      <Header />

      <main
        className={clsx(classes.content, {
          [classes.contentShift]: false,
        })}
      >
        <div className={classes.drawerHeader} />
        <Switch>
          <Route exact path="/" component={Home} />
          <Route path="/Topic/:topicLink" render={renderAlgorithmPicker} />
          <Route path="/:SomethingElse" component={Home} />
        </Switch>
      </main>
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
