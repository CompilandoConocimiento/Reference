import React, { useState, useEffect } from "react"
import { Sidenav } from "materialize-css/"

import NavigationMenu from "./NavigationMenu"
import SideMenu from "./SideMenu"

/**
 * The AppHeader return the merge of NavigationMenu and SideMenu, just that,
 * and initialization the sidenav of MaterializeCSS.
 */

const AppHeader: React.FunctionComponent = () => {
  const [sideNav, setSideNav] = useState<M.Sidenav | null>(null)
  const closeSideMenu = () => setTimeout(() => sideNav && sideNav.close(), 400)

  useEffect(() => {
    const node = document.getElementById("SideBarID")
    node && setSideNav(Sidenav.init(node, { draggable: true, edge: "left" }))
  }, [])

  return (
    <React.Fragment>
      <NavigationMenu />
      <SideMenu CloseSideMenu={closeSideMenu} />
    </React.Fragment>
  )
}

export default AppHeader
