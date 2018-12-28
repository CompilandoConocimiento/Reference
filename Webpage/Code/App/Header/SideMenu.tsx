import React from "react"
import { Link } from 'react-router-dom'

import { DirectoryData } from '../../Data'

const LinkToTopic: React.FunctionComponent<{link: string, size: string, onClick: () => void}> = props => (
    <Link className="waves-effect" onClick={props.onClick} to={props.link}>
        <span style={{fontSize: props.size}}>
            {props.children}
        </span>
    </Link>
)

interface SideMenuProps { CloseSideMenu: () => void }
const SideMenu: React.FunctionComponent<SideMenuProps> = props => {

    const TopicsLink = DirectoryData.map( (Topic, indexTopic) =>
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
                Topic.subTopics.map( (SubTopic, indexSubTopic) =>
                    <li key={indexSubTopic}>
                        <LinkToTopic 
                            link    = {`/Topic/${Topic.link}/${SubTopic.link}`}
                            onClick = {props.CloseSideMenu}
                            size    = "0.95rem">
                            &nbsp;&nbsp;{SubTopic.name}
                        </LinkToTopic>
                    </li>
                )
            }
        </React.Fragment>
    )
  
    return (
        <ul id="SideBarID" className="sidenav">

            <li>
                <br />
                <h5 className="blue-grey-text text-darken-3">
                    <span style={{fontWeight: 500, fontSize: "2.1rem"}}>
                        &nbsp;&nbsp;&nbsp;&nbsp; <b>Topics</b>
                    </span>
                </h5>
            </li>

            <br />

            {TopicsLink}

            <br /><br />
            <br /><br />

        </ul>
    )
}

export default SideMenu