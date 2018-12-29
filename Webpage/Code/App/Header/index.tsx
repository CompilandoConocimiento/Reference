import React from "react"
import { Sidenav } from "materialize-css/"

import NavigationMenu from "./NavigationMenu"
import SideMenu       from "./SideMenu"

interface AppHeaderState { Sidenav?: M.Sidenav }
interface AppHeaderProps { }

/**
   * The AppHeader return the merge of NavigationMenu and SideMenu, just that,
   * and initialization the sidenav of MaterializeCSS.
   */
export default class AppHeader extends React.Component<AppHeaderProps, AppHeaderState> {

    constructor(props: AppHeaderProps) {
        super(props)
        this.state = {}
    }

    componentDidMount() {
        const elementNode = document.getElementById('SideBarID')!
        this.setState({Sidenav: Sidenav.init(elementNode, {draggable: true, edge: "left"})})
    }

    closeSideMenu () {
        setTimeout( () => this.state.Sidenav!.close(), 400)
    }

    render () {
        return (
            <React.Fragment>
                <NavigationMenu />
                <SideMenu CloseSideMenu={() => this.closeSideMenu()} />
            </React.Fragment>
        )
      }
}