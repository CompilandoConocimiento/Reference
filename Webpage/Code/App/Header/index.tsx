import React from "react"
import { Sidenav } from "materialize-css/"

import NavigationMenu from "./NavigationMenu"
import SideMenu       from "./SideMenu"

interface AppHeaderState { Sidenav: M.Sidenav | null }
interface AppHeaderProps { }

export default class AppHeader extends React.Component<AppHeaderProps, AppHeaderState> {

    constructor(props: AppHeaderProps) {
        super(props)
        this.state = { Sidenav: null }
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