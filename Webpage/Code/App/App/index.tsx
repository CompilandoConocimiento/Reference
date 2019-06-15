import ReactDOM from "react-dom"
import React, { FunctionComponent, useContext, useState } from "react"
import { Switch, Route, RouteComponentProps } from "react-router-dom"

import CssBaseline from "@material-ui/core/CssBaseline"
import clsx from "clsx"

import Header from "../Header"
import Home from "../Home"
import AlgorithmsPicker from "../AlgorithmsPicker"
import { ErrorMessage } from "../Helpers"

import Wrapper, { IndexDataContext, isDrawerOpenDesktopContext } from "./Wrapper"
import useHeaderStyles from "../Header/Styles"

/**
 * This is a wrapper of all the app, the header, the footer and
 * the content. It also moves if we have the drawer open
 */
const App: FunctionComponent = () => {
  const drawerSituation = useState(false)
  const [isDrawerOpen] = drawerSituation

  const Styles = useHeaderStyles()
  const ContentMargin = clsx(Styles.Content, { [Styles.ContentShift]: isDrawerOpen })

  const TopicsData = useContext(IndexDataContext)

  type RouteDataTopicLink = RouteComponentProps<{ topicLink: string }>
  const showAlgorithmPicker = (props: RouteDataTopicLink) => {
    const topicLink = props.match.params.topicLink
    const topic = TopicsData.find(Topic => Topic.link === topicLink)
    if (!topic) return <ErrorMessage />

    return <AlgorithmsPicker TopicData={topic} />
  }

  return (
    <Wrapper>
      <div className={Styles.Root}>
        <CssBaseline />
        <isDrawerOpenDesktopContext.Provider value={drawerSituation}>
          <Header />

          <main className={ContentMargin}>
            <div className={Styles.SpaceForTheHeader} />
            <Switch>
              <Route exact path="/" component={Home} />
              <Route path="/Topic/:topicLink" render={showAlgorithmPicker} />
              <Route path="/:SomethingElse" component={Home} />
            </Switch>
          </main>
        </isDrawerOpenDesktopContext.Provider>
      </div>
    </Wrapper>
  )
}

const DOMNode = document.getElementById("ReactApp")
ReactDOM.render(<App />, DOMNode)

export { IndexDataContext }
