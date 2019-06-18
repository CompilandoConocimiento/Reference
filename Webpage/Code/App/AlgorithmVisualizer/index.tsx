import React, { FunctionComponent, Suspense, useState, Dispatch, SetStateAction } from "react"

import { Typography, Box } from "@material-ui/core"
import { AlgorithmData } from "../../Data/Types"
import { Loading } from "../Helpers"

import FAB from "./FAB"
import useStyles from "./Styles"

const linkToServer = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"

type ContextCodeType = [{ [key: string]: Array<string> }, (fileName: string) => void]
const defaultValue = [{}, (fileName: string) => console.log(fileName)] as ContextCodeType
const CodeDataContext = React.createContext(defaultValue)

const defaultStyle = { fontSize: "1rem", style: "dracula" }
const CodeStyleContext = React.createContext(defaultStyle)
type setStateFn = Dispatch<SetStateAction<typeof defaultStyle>>
const EditCodeStyleContext = React.createContext<setStateFn>(() => {})

type VisualizerType = FunctionComponent<{ AlgorithmData: AlgorithmData; TopicLink: string }>
const AlgorithmVisualizer: VisualizerType = ({ AlgorithmData, TopicLink }) => {
  const Styles = useStyles()

  const [codeStyle, updatecodeStyle] = useState(defaultStyle)
  const [codeFilesData, changeCodeFileData] = useState<{ [key: string]: Array<string> }>({})
  const getCodeData = (fileName: string) => {
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
  const setNextStyle = (fileName: string) => {
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
      <div className={Styles.ArticleTitle}>
        <Typography gutterBottom variant="h4">
          <Box fontWeight={500}>{AlgorithmData.name}</Box>
        </Typography>
      </div>

      <div className={Styles.ArticleBody}>
        <Suspense fallback={<Loading />}>
          <EditCodeStyleContext.Provider value={updatecodeStyle}>
            <CodeStyleContext.Provider value={codeStyle}>
              <CodeDataContext.Provider value={[codeFilesData, getCodeData]}>
                <AlgorithmData.Component />
              </CodeDataContext.Provider>

              <FAB />
            </CodeStyleContext.Provider>
          </EditCodeStyleContext.Provider>
        </Suspense>
      </div>
    </React.Fragment>
  )
}

export { CodeDataContext, CodeStyleContext, EditCodeStyleContext }
export default AlgorithmVisualizer
