import React from "react"
import { Link } from 'react-router-dom'

import TopicsData from '../../Data/TopicsData'

/**
   * A react router link that send you to a topic.
   * 
   * @param link The link to the topic 
   * @param size The size of the link using CSS fontSize, (ei "1.15rem")
   * @param onClick A callback to call when user clicks 
   */
const LinkToTopic: React.FunctionComponent<{link: string, size: string, onClick: () => void}> = props => (
    <Link className="waves-effect" onClick={props.onClick} to={props.link}>
        <span style={{fontSize: props.size}}>
            {props.children}
        </span>
    </Link>
)

interface SideMenuProps { CloseSideMenu: () => void }

/**
   * We use the TopicsData to generate a side menu index, it renders an array of <li>
   * that that have the topic name, divider and links to algorithms.
   * 
   * @param CloseSideMenu  A callback to call when user clicks (that should close the side menu)
   */
const SideMenu: React.FunctionComponent<SideMenuProps> = props => {

    const TopicsLink = TopicsData.map( (Topic, indexTopic) =>
        <React.Fragment key={indexTopic}>
            <li>
                <div className="divider" />
            </li>

            <li>
                <LinkToTopic link={`/Topic/${Topic.link}/`} size="1.1rem" onClick={props.CloseSideMenu}>
                    {Topic.name}
                </LinkToTopic>
            </li>

            {
                Topic.Algorithms.map( (Algorithm, indexSubTopic) =>
                    <li key={indexSubTopic}>
                        <LinkToTopic 
                            link    = {`/Topic/${Topic.link}/${Algorithm.link}`}
                            onClick = {props.CloseSideMenu}
                            size    = "0.95rem">
                            &nbsp;&nbsp;{Algorithm.name}
                        </LinkToTopic>
                    </li>
                )
            }
        </React.Fragment>
    )
  
    return (
        <ul id="SideBarID" className="sidenav">
            <li>
                <h5 className="blue-grey-text text-darken-3" style={{margin: "32px"}}>
                    <span style={{fontWeight: 500, fontSize: "2.1rem"}}>
                        &nbsp;&nbsp;<b>Topics</b>
                    </span>
                    <a className="modal-trigger" href="#modalConfig">
                        <i className="material-icons right blue-grey-text text-darken-3">edit</i>
                    </a> 
                </h5>
            </li>

            {TopicsLink}

            <br /><br />
            <br /><br />

        </ul>
    )
}

export default SideMenu