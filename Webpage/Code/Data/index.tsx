import DirectoryData from "./Directory"
export const Directory = DirectoryData


//Update the directory
//import SaveData from "./UpdateDirectory"
//SaveData(Topics, "Directory.json")

//import DynamicProgramming from './DynamicProgramming'
//import Search             from './Search'
//import Strings            from './Strings'
import NumberTheory         from './NumberTheory'

export const Topics: Array<Topic> = [
    NumberTheory,
]


import {Topic as TopicInterface, SubTopic as SubTopicInterface} from "./types"
import {NameLink as NameLinkInterface, DirectoryTopic as DirectoryTopicInterface} from "./types"

export type Topic = TopicInterface
export type SubTopic = SubTopicInterface

export type NameLink = NameLinkInterface
export type DirectoryTopic = DirectoryTopicInterface
