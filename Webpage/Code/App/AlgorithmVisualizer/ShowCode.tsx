import React, { FunctionComponent, useContext, useState } from "react"
import SyntaxHighlighter from "react-syntax-highlighter"

import { Snackbar } from "@material-ui/core/"

import { TopicDataLinkContext } from "../AlgorithmsPicker"
import { CodeDataContext, CodeStyleContext } from "../App"
import { Loading } from "../Helpers"

import copyText from "./CodeActions"

import { baseCodeStyle, getCodeStyle } from "./Styles"

type CodeType = FunctionComponent<{ language: string; fileName: string; lines: [number, number] }>
const Code: CodeType = ({ language, fileName, lines }) => {
  const codeStyle = useContext(CodeStyleContext)
  const [codeData, getCodeFile] = useContext(CodeDataContext)
  const topicLink = useContext(TopicDataLinkContext)
  const [isSnackbarOpen, changeOpenSnackbar] = useState(false)

  if (codeData[fileName] === undefined) {
    getCodeFile(fileName, topicLink)
    return <Loading />
  }

  const [start, end] = lines
  const codeTextLines = codeData[fileName].slice(start - 1, end)
  const style = getCodeStyle(codeStyle.style)
  const customStyle = { ...baseCodeStyle, fontSize: codeStyle.fontSize }

  return (
    <React.Fragment>
      <Snackbar
        anchorOrigin={{ vertical: "bottom", horizontal: "left" }}
        open={isSnackbarOpen}
        autoHideDuration={6000}
        onClose={() => changeOpenSnackbar(false)}
        message={<span>Code copied to clipboard ;)</span>}
      />

      <SyntaxHighlighter
        {...{ customStyle, language, style }}
        onDoubleClick={() => {
          changeOpenSnackbar(true)
          copyText(codeTextLines)
        }}
      >
        {codeTextLines.join("\n")}
      </SyntaxHighlighter>
    </React.Fragment>
  )
}

export default Code
