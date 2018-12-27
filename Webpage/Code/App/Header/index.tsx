import React from "react"
import M from "materialize-css"

import NavigationMenu from "./NavigationMenu"
import SideMenu from "./SideMenu"
interface AppHeaderState {
	Sidenav: M.Sidenav | null
}

interface AppHeaderProps {
	Sidenav: M.Sidenav | null
}
export default class AppHeader extends React.Component<{}, AppHeaderState> {

	constructor(props: AppHeaderProps) {
		super(props)
		this.state = { Sidenav: null }
	}

  	componentDidMount() {
        const elementNode = document.getElementById('SideBarID')!
        this.setState({Sidenav: M.Sidenav.init(elementNode, {draggable: true, edge: "left"})})
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