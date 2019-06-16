import React, { FunctionComponent, useState, useEffect, Fragment } from "react"
import M from "materialize-css"

import { AlgorithmData } from "../../Data"
import { Loading } from "../Helpers"
import getCodeText from "./GetCodeText"
import FAB, { FABElement } from "./FAB"
import ConfigContext from "./ConfigContext"

import * as Styles from "./Styles.css"

const linkToServer = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"

interface VisualizerProps {
  AlgorithmData: AlgorithmData
  TopicLink: string
}

const AlgorithmVisualizer2: FunctionComponent<VisualizerProps> = props => {
  const [Component, setComponent] = useState<any>(null)
  const [Config, setConfig] = useState<any>(null)
  useEffect(() => {
    props.AlgorithmData.module()
      .then(module => module.default)
      .then(moduleData => {
        setComponent(() => moduleData.Component)
        setConfig(moduleData.Config)
      })
  }, [])

  // WFT HOW DO YOU KNOW SIZE AFTER CHANGING PAGE??
  const [componentDidReallyMount, mount] = useState(false)
  useEffect(() => {
    if (Component) window["MathJax"].Hub.Typeset()
  }, [componentDidReallyMount])

  const [code, setCode] = useState<any>(null)
  useEffect(() => {
    if (Component && Config) {
      const baseLink = `${linkToServer}/Code/${props.TopicLink}`
      getCodeText(baseLink, Config.filesData, setCode)
    }
  }, [componentDidReallyMount])

  const [modal, setModal] = useState<any>(null)
  useEffect(() => {
    const modalNode = document.querySelector(".modal")
    setModal(M.Modal.init(modalNode!, {}))
  }, [])

  const FABToDo: FABElement[] = [
    {
      color: "teal",
      closeOnClick: true,
      icon: "palette",
      onClick: () => modal && modal.open(),
    },
    {
      color: "indigo",
      closeOnClick: false,
      icon: "code",
      onClick: () => {
        M.Toast.dismissAll()
        M.toast({ html: "Toggle comments" })

        document.querySelectorAll(".hljs-comment").forEach((comment: any) => {
          if (comment.style.display === "") comment.style.display = "initial"
          comment.style.display = comment.style.display == "initial" ? "none" : "initial"
        })
      },
    },
    {
      color: "blue",
      closeOnClick: true,
      icon: "content_copy",
      onClick: () => M.toast({ html: "Just double click the code you want" }),
    },
    {
      color: "green",
      closeOnClick: true,
      icon: "arrow_upward",
      onClick: () => {
        const newConfig = { ...Config }
        newConfig.CodeConfig.CodeStyles.fontSize += 0.1
        setConfig(newConfig)
      },
    },
    {
      color: "red",
      closeOnClick: true,
      icon: "arrow_downward",
      onClick: () => {
        const newConfig = { ...Config }
        newConfig.CodeConfig.CodeStyles.fontSize -= 0.1
        setConfig(newConfig)
      },
    },
  ]

  if (!Component || !Config) return <Loading />
  if (!componentDidReallyMount) mount(true)

  return (
    <Fragment>
      <div className="center blue-grey-text text-darken-3">
        <h4>{props.AlgorithmData.name}</h4>
      </div>

      <br />

      <div className={"container " + Styles.Text}>
        <ConfigContext.Provider value={Config.CodeConfig}>
          <Component filesData={code} />
        </ConfigContext.Provider>
      </div>

      <FAB FABElements={FABToDo} />
    </Fragment>
  )
}

export default AlgorithmVisualizer2
