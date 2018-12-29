import React from "react"
import * as Styles from "./Styles.css"

export interface FABElement {
    color: string,
    icon: string,
    closeOnClick: boolean,
    onClick: () => void,
}
/**
   * A MaterializeCSS  Button
   */
const FABButton: React.FunctionComponent<FABElement & {closeFAB: any}> = props => (
    <li>
        <a
            className = {"btn-floating " + props.color}
            onClick   = { props.closeOnClick? () => { props.onClick(); props.closeFAB() } : props.onClick}>
            <i className ="material-icons">{props.icon}</i>
        </a>
    </li>
)

/**
   * A MaterializeCSS FAB
   */
interface FABProps {FABElements: FABElement[]}
interface FABState {FAB?: M.FloatingActionButton}

export default class FAB extends React.Component<FABProps, FABState> {

    constructor(props: {FABElements: FABElement[]}) { 
        super(props)
        this.state = {}
    }

    componentDidMount() {
        const FABNode = document.getElementById('FAB')!
        this.setState({FAB: M.FloatingActionButton.init(FABNode, {})})
    }

    render () {
        return (
            <div id="FAB" className="fixed-action-btn">
                <a className="btn-floating btn-large red">
                    <i className="large material-icons">mode_edit</i>
                </a>
                <ul className={Styles.UnSelectable}>
                    { 
                        this.props.FABElements.map( (element, index) => 
                            <FABButton key={index} {...element} closeFAB={() => this.state.FAB!.close()} />
                        )
                    }
                </ul>
            </div>
        )
    }
}