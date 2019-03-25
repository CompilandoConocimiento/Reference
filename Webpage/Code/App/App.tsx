import React, { FunctionComponent } from "react"
import ReactDOM from "react-dom"
import { HashRouter, Switch, Route } from "react-router-dom"

import TopicsData from "../Data/TopicsData"

import Header from "./Header"
import Footer from "./Footer"
import Home from "./Home"
import AlgorithmsPicker from "./AlgorithmsPicker"
import { ErrorMessage } from "./Helpers";

export const IndexDataContext = React.createContext(TopicsData)
/**
 * This is a wrapper of all the app, the header, the footer and
 * the content.
 */
const App: FunctionComponent = () => (
  <IndexDataContext.Provider value={TopicsData}>
    <Header />

    <main>
      <Switch>
        <Route exact path="/" component={Home} />
        <Route
          path="/Topic/:topicLink"
          render={props => {
            const topicLink = props.match.params.topicLink
            const topic = TopicsData.find(Topic => Topic.link === topicLink)
            if (!topic) return <ErrorMessage />
            else return <AlgorithmsPicker TopicData={topic} />
          }}
        />
        <Route path="/:SomethingElse" component={Home} />
      </Switch>
    </main>

    <Footer />
  </IndexDataContext.Provider>
)

ReactDOM.render(
  <React.StrictMode>
    <HashRouter>
      <App />
    </HashRouter>
  </React.StrictMode>,
  document.getElementById("ReactApp")
)
