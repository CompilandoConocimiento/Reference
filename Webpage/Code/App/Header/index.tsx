import React, { useState, useEffect, FunctionComponent } from "react"
import { Sidenav } from "materialize-css/"

import NavigationMenu from "./NavigationMenu"
import SideMenu from "./SideMenu"

/**
 * The AppHeader return the merge of NavigationMenu and SideMenu, just that,
 * and initialization the sidenav of MaterializeCSS.
 */

const AppHeader: FunctionComponent = () => {
  const [sideNav, setSideNav] = useState<M.Sidenav | null>(null)
  const onClose = () => setTimeout(() => sideNav && sideNav.close(), 400)
  const sideMenuID = "SideBarID";

  useEffect(() => {
    const node = document.getElementById("SideBarID")
    node && setSideNav(Sidenav.init(node, { draggable: true, edge: "left" }))
  }, [])

  return (
    <header>
      <NavigationMenu {...{sideMenuID}} />
      <SideMenu {...{sideMenuID, onClose}} />
      <br />
    </header>
  )
}

export default AppHeader
