import ReactDOM from "react-dom"
import React, { FunctionComponent, useState, useContext, Dispatch, SetStateAction } from "react"
import { Switch, Route } from "react-router-dom"

import clsx from "clsx"

import Header from "../Header"
import Home from "../Home"
import Footer from "../Footer"
import AlgorithmsPicker from "../AlgorithmsPicker"

import Wrapper, { DataContext } from "./Wrapper"
import { DrawerSituationDesktopContext, ChangeDrawerSituationDesktopContext } from "./Wrapper"
import { ErrorMessage } from "../Helpers"

import useHeaderStyles from "../Header/Styles"

const defaultStyle = { fontSize: "1rem", style: "dracula" }
const CodeStyleContext = React.createContext(defaultStyle)
type setStateFn = Dispatch<SetStateAction<typeof defaultStyle>>
const EditCodeStyleContext = React.createContext<setStateFn>(() => {})

type functionType = (fileName: string, TopicLink: string) => void
type ContextCodeType = [{ [key: string]: Array<string> }, functionType]
const defaultValue = [{}, () => {}] as ContextCodeType
const CodeDataContext = React.createContext(defaultValue)

const linkToServer = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"

/**
 * This is a wrapper of all the app, the header, the footer and
 * the content. It also moves the content if we have the drawer open
 */
const App: FunctionComponent = () => {
  const TopicsData = useContext(DataContext)
  const isDesktopDrawerOpen = useContext(DrawerSituationDesktopContext)
  const [codeStyle, updatecodeStyle] = useState(defaultStyle)

  const headerStyles = useHeaderStyles()
  const ContentStyle = clsx(headerStyles.Content, {
    [headerStyles.ContentShift]: isDesktopDrawerOpen,
  })

  const [codeFilesData, changeCodeFileData] = useState<{ [key: string]: Array<string> }>({})
  const getCodeData = (fileName: string, TopicLink: string) => {
    const linkToFile = `${linkToServer}/Code/${TopicLink}/${fileName}`
    fetch(linkToFile)
      .then(response => response.text())
      .then(text => text.split("\n"))
      .then(lines =>
        changeCodeFileData(codeData => {
          const newData = { ...codeData }
          newData[fileName] = lines
          return newData
        })
      )
  }

  return (
    <React.Fragment>
      <Header />
      <div className={ContentStyle}>
        <div className={headerStyles.SpaceForTheHeader} />

        <CodeDataContext.Provider value={[codeFilesData, getCodeData]}>
          <EditCodeStyleContext.Provider value={updatecodeStyle}>
            <CodeStyleContext.Provider value={codeStyle}>
              <main className={headerStyles.ContentPadding}>
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
            </CodeStyleContext.Provider>
          </EditCodeStyleContext.Provider>
        </CodeDataContext.Provider>

        <Footer />
      </div>
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

export {
  CodeStyleContext,
  EditCodeStyleContext,
  DataContext,
  CodeDataContext,
  DrawerSituationDesktopContext,
  ChangeDrawerSituationDesktopContext,
}
