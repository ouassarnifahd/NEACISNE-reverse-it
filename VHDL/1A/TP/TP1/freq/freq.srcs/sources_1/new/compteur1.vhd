----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14.03.2017 11:23:30
-- Design Name: 
-- Module Name: compteur1 - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity compteur1 is
    Port ( clk : in STD_LOGIC;
           TTL_mef : in STD_LOGIC;
           valid : in STD_LOGIC;
           raz : in STD_LOGIC;
           freq : out STD_LOGIC_VECTOR (15 downto 0));
end compteur1;

architecture Behavioral of compteur1 is

begin


end Behavioral;
