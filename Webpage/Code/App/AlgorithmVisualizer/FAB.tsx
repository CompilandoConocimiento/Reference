import React, { useState, useCallback, useContext } from "react"

import { SpeedDial, SpeedDialAction } from "@material-ui/lab/"
import { Snackbar } from "@material-ui/core/"
import { Edit, ArrowUpward, ArrowDownward, Palette } from "@material-ui/icons"
import { green, red, purple } from "@material-ui/core/colors"

import { EditCodeStyleContext, CodeStyleContext } from "../App"
import usetyles, { themes } from "./Styles"

const FAB = () => {
  const Styles = usetyles()
  const codeStyle = useContext(CodeStyleContext)
  const [isFABOpen, changeFABStatus] = useState(false)
  const [isSnackbarOpen, changeOpenSnackbar] = useState(false)
  const changeCodeStyle = useContext(EditCodeStyleContext)

  const handleOpenSnackbar = useCallback(() => changeOpenSnackbar(true), [])
  const handleCloseSnackbar = useCallback(() => changeOpenSnackbar(false), [])
  const toggleOpenFAB = useCallback(() => changeFABStatus(open => !open), [])
  const handleOpenFAB = useCallback(() => changeFABStatus(true), [])
  const handleCloseFAB = useCallback(() => changeFABStatus(false), [])
  const changeFontSize = useCallback(
    (step: number) =>
      changeCodeStyle(style => {
        const newStyle = { ...style }
        const oldFontSize = parseFloat(style.fontSize.substring(0, style.fontSize.length - 3))
        newStyle.fontSize = `${Math.max(oldFontSize + step, 0.2)}rem`
        return newStyle
      }),
    [changeCodeStyle]
  )
  const changetoNextStyle = useCallback(
    () =>
      changeCodeStyle(style => {
        const newStyle = { ...style }
        const index = themes.findIndex(theme => theme === style.style) + 1
        newStyle.style = themes[index % themes.length]

        handleOpenSnackbar()

        return newStyle
      }),
    [changeCodeStyle, handleOpenSnackbar]
  )

  return (
    <React.Fragment>
      <Snackbar
        anchorOrigin={{ vertical: "bottom", horizontal: "left" }}
        open={isSnackbarOpen}
        autoHideDuration={6000}
        onClose={handleCloseSnackbar}
        message={<span>Theme changed to {codeStyle.style}</span>}
      />
      <SpeedDial
        ariaLabel="SpeedDial tooltip example"
        className={Styles.FAB}
        hidden={false}
        icon={<Edit />}
        onBlur={handleCloseFAB}
        onClick={toggleOpenFAB}
        onClose={handleCloseFAB}
        onFocus={handleOpenFAB}
        onMouseEnter={handleOpenFAB}
        onMouseLeave={handleCloseFAB}
        open={isFABOpen}
      >
        <SpeedDialAction
          icon={<ArrowDownward style={{ color: red[500] }} />}
          tooltipTitle={"Smaller font"}
          tooltipOpen
          onClick={() => changeFontSize(-0.1)}
        />
        <SpeedDialAction
          icon={<ArrowUpward style={{ color: green[500] }} />}
          tooltipTitle={"Bigger font"}
          tooltipOpen
          onClick={() => changeFontSize(0.1)}
        />
        <SpeedDialAction
          icon={<Palette style={{ color: purple[500] }} />}
          tooltipTitle={"Change theme"}
          tooltipOpen
          onClick={changetoNextStyle}
        />
      </SpeedDial>
    </React.Fragment>
  )
}

export default FAB
