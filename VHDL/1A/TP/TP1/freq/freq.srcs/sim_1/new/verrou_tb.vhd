library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity verrou_tb is
--  Port ( );
end verrou_tb;

architecture Behavioral of verrou_tb is

    component verrou is
        Port ( clk : in STD_LOGIC;
               verr : in STD_LOGIC;
               freq : in STD_LOGIC_VECTOR (15 downto 0);
               freq_verr : out STD_LOGIC_VECTOR (15 downto 0));
    end component verrou;
    
signal clk : std_logic :='0';
signal verr : STD_LOGIC :='0';
signal freq : STD_LOGIC_VECTOR (15 downto 0) := X"0000";
    
signal freq_verr : std_logic_vector (15 downto 0);
    
begin

    dut : verrou PORT MAP(
                clk => clk,
                verr => verr,
                freq => freq,
                freq_verr => freq_verr);


p1: process
    begin
        clk <= '0';
        wait for 5 ns;
        clk <= '1';
        wait for 5 ns;
    end process;
    
p2: process
    begin
        verr <='0';
        wait for 1000000000 ns;
        verr <= '1';
        wait;
    end process;

end Behavioral;
