import React, { FunctionComponent, Suspense, useState, Dispatch, SetStateAction } from "react"

import { Typography, Box } from "@material-ui/core"

import { AlgorithmData } from "../../Data/Types"
import { Loading } from "../Helpers"

import useStyles from "./Styles"

interface CodeStateType {
  [key: string]: Array<string>
}
type ContextType = [CodeStateType, Dispatch<SetStateAction<CodeStateType>>]
const CodeDataContext = React.createContext<ContextType>([{}, () => {}])
const LinkContext = React.createContext<string>("")

interface VisualizerProps {
  AlgorithmData: AlgorithmData
  TopicLink: string
}

const AlgorithmVisualizer: FunctionComponent<VisualizerProps> = ({ AlgorithmData, TopicLink }) => {
  const Styles = useStyles()
  const CodeState = useState<CodeStateType>({})

  const linkToServer = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"
  const baseLink = `${linkToServer}/Code/${TopicLink}`

  return (
    <CodeDataContext.Provider value={CodeState}>
      <LinkContext.Provider value={baseLink}>
        <div className={Styles.ArticleTitle}>
          <Typography gutterBottom variant="h4">
            <Box fontWeight={500}>{AlgorithmData.name}</Box>
          </Typography>
        </div>
        <div className={Styles.ArticleBody}>
          <Suspense fallback={<Loading />}>
            <AlgorithmData.Component />
          </Suspense>
        </div>
      </LinkContext.Provider>
    </CodeDataContext.Provider>
  )
}

export { CodeDataContext, LinkContext }
export default AlgorithmVisualizer
